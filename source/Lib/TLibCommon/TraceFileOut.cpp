#include "TraceFileOut.h"
#include <stdio.h>

void TraceFileOutDefault( uint8_t *pData, int dataLen )
{
	char *pOutData = (char *)pData;
	FILE *pDefaultOutFile;
	pDefaultOutFile = fopen("E:\\defaultOutFile.txt","a+");

	fseek(pDefaultOutFile,0,SEEK_SET);
	fseek(pDefaultOutFile,0,SEEK_END);
	int64_t nFileLen = ftell(pDefaultOutFile);
	fseek(pDefaultOutFile,0,SEEK_SET);
	if (nFileLen == 0)
	{
		for (int i = 0;i < 32;i++)
		{
			fprintf(pDefaultOutFile,"%4u ",i);
		}
	}
	fprintf(pDefaultOutFile,"\n\n");
	for (int i = 0;i < dataLen;i++)
	{
		fprintf(pDefaultOutFile,"%4u ",(unsigned char)pOutData[i]);
	}

	fclose(pDefaultOutFile);
}

void TraceFileOut( uint8_t *pData, int dataLen, TCHAR fileName[] )
{
	char *pOutData = (char *)pData;
	FILE *pTargetFile;
	_tfopen_s(&pTargetFile,fileName,_T("w"));

	fprintf(pTargetFile,"current size = %d \n",dataLen);
	for (int i = 0;i < 32;i++)
	{
		fprintf(pTargetFile,"%4u ",i);
	}
	fprintf(pTargetFile,"\n\n");

	for (int i = 0;i < dataLen;i++)
	{
		fprintf(pTargetFile,"%4u ",(unsigned char)pOutData[i]);
	}
	fclose(pTargetFile);
}

void TraceMatrixFileOut( uint8_t *pData, int nWidth, int nHeight, TCHAR fileName[],  TCHAR traceMode[])
{
	unsigned char *pOutData = (unsigned char *)pData;
	FILE *pTargetFile;
	_tfopen_s(&pTargetFile,fileName,_T("w"));

	for (int i = 0;i < nWidth; i++)
	{
		fprintf(pTargetFile,"%4u ",i);
	}
	fprintf(pTargetFile,"\n");

	if (0 == _tcsicmp(traceMode,_T("Int2Pxl")))
	{
		int actualWidth = nWidth * 4;
		for (int i = 0;i < nHeight;i++)
		{
			for (int j = 0; j < actualWidth; j+=4)
			{
				int pelVal = 0;
				for (int x = 0;x < 4;x++)
				{
					pelVal += (pOutData[i * actualWidth + j + x] << (x*8));
				}
				if(pelVal > 255 || pelVal < 0)
				{
					pelVal = '#';
					fprintf(pTargetFile,"%4c ",pelVal);
				}
				else
				{
					fprintf(pTargetFile,"%4u ",pelVal);
				}
			}
			fprintf(pTargetFile,"\n");
		}
	} 
	else if (0 == _tcsicmp(traceMode,_T("Sht2Pxl")))
	{
		int actualWidth = nWidth * 2;
		for (int i = 0;i < nHeight;i++)
		{
			for (int j = 0; j < actualWidth; j+=2)
			{
				int pelVal = 0;
				for (int x = 0;x < 2;x++)
				{
					pelVal += (pOutData[i * actualWidth + j + x] << (x*8));
				}
				if(pelVal > 255 || pelVal < 0)
				{
					pelVal = '#';
					fprintf(pTargetFile,"%4c ",pelVal);
				}
				else
				{
					fprintf(pTargetFile,"%4u ",pelVal);
				}
			}
			fprintf(pTargetFile,"\n");
		}
	}
	else if (0 == _tcsicmp(traceMode,_T("UCh2Sht")))
	{
		int nSize = sizeof(short);
		short *pShortData = (short *)pData;
		for (int i = 0;i < nHeight;i++)
		{
			for (int j = 0; j < nWidth; j++)
			{
				fprintf(pTargetFile,"%4d ",pShortData[i * nHeight + j]);		
			}
			fprintf(pTargetFile,"\n");
		}
	}
	else
	{
		for (int i = 0;i < nHeight;i++)
		{
			for (int j = 0; j < nWidth; j++)
			{
				fprintf(pTargetFile,"%4u ",(unsigned char)pOutData[i * nHeight + j]);		
			}
			fprintf(pTargetFile,"\n");
		}
	}

	fclose(pTargetFile);
}
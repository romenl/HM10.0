#pragma once
#include <stdint.h>
#include <tchar.h>
void TraceFileOutDefault(uint8_t *pData, int dataLen);
void TraceFileOut(uint8_t *pData, int dataLen, TCHAR fileName[]);
void TraceMatrixFileOut( uint8_t *pData, int nWidth, int nHeight, TCHAR fileName[], TCHAR traceMode[] );

//***
//��¼ģʽ��
//1��"Int2Pxl"������һ��int������ת��Ϊ����ֵ��[0,255]֮�����ֵ�á�#�����
//2��"Sht2Pxl"������һ��short������ת��Ϊ����ֵ��[0,255]֮�����ֵ�á�#�����
//3��"Residual"���������Ĳв�����
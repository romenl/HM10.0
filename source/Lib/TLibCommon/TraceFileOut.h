#pragma once
#include <stdint.h>
#include <tchar.h>
void TraceFileOutDefault(uint8_t *pData, int dataLen);
void TraceFileOut(uint8_t *pData, int dataLen, TCHAR fileName[]);
void TraceMatrixFileOut( uint8_t *pData, int nWidth, int nHeight, TCHAR fileName[], TCHAR traceMode[] );

//***
//记录模式：
//1："Int2Pxl"——将一个int型数据转换为像素值，[0,255]之外的数值用‘#’替代
//2："Sht2Pxl"——将一个short型数据转换为像素值，[0,255]之外的数值用‘#’替代
//3："Residual"——输出块的残差数据
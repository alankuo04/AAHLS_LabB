#ifndef _BLOCK_MM_H_
#define _BLOCK_MM_H_
#include "hls_stream.h"
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

typedef int DTYPE;

#define N 32
#define M 32
#define P 32

void matrixmul(int A[N][M], int B[M][P], int AB[N][P]);

#endif

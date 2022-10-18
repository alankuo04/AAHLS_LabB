#include "CompleteMatrix.h"
#include <stdlib.h>
using namespace std;

void matmatmul_sw(DTYPE A[M][N], DTYPE B[N][P],
	DTYPE out[M][P]){
	DTYPE sum = 0;
	for(int i = 0; i < M; i++){
		for(int j = 0;j<P; j++){
			sum = 0;
			for(int k = 0; k < N; k++){
				sum = sum + A[i][k] * B[k][j];
			}
			out[i][j] = sum;
		}
	}
}

int main() {
	int fail = 0;
	DTYPE A[M][N], B[N][P];
	DTYPE matrix_swout[M][N], matrix_hwout[N][P];

	initmatrices: for(int i = 0; i < M; i++){
		for(int j = 0; j < M; j++){
			A[i][j] = rand() % 512;
			B[i][j] = rand() % 512;
			matrix_swout[i][j] = 0;
			matrix_hwout[i][j] = 0;
		}
	}

	matrixmul(A, B, matrix_hwout);

	matmatmul_sw(A, B, matrix_swout);

	for(int i = 0; i<M; i++)
		for(int j = 0; j<M; j++)
			if(matrix_swout[i][j] != matrix_hwout[i][j]) { fail=1; }


	if(fail==1) cout << "failed" << endl;
	else cout << "passed" << endl;

	return 0;
}

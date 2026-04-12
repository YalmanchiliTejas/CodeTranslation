#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int N,S[3030]; long long D[3030][3030];

int main()
{
	scanf ("%d",&N);
	for (int i=0;i<N;i++) scanf ("%d",&S[i]), D[i][i] = S[i];
	for (int l=1;l<N;l++){
		for (int i=0,j=l;j<N;i++,j++){
			D[i][j] = S[i] - D[i+1][j];
			if (D[i][j] < S[j] - D[i][j-1])
				D[i][j] = S[j] - D[i][j-1];
		}
	}
	printf ("%lld\n",D[0][N-1]);

	return 0;
}
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

const int mod = 1000000007;

char N[10101];
int D,P[10101]; long long U[10001][101];

int main()
{
	scanf ("%s %d",N,&D);
	U[0][0] = 1;
	for (int i=1;i<=10000;i++){
		for (int j=0;j<D;j++) for (int x=0;x<10;x++){
			long long &u = U[i][(j+x)%D];
			u = (u + U[i-1][j]) % mod;
		}
	}

	int L = 0;
	while (N[L]) L++;

	for (int i=0;i<L;i++) P[i] = (N[i] - '0') % D;
	for (int i=1;i<L;i++) P[i] = (P[i-1] + P[i]) % D;

	long long ans = (P[L-1] == 0);
	for (int i=0;i<L;i++){
		for (int j=0;j<N[i]-'0';j++){
			for (int k=0;k<D;k++){
				int d = (j + k) % D;
				if (i) d = (d + P[i-1]) % D;
				if (d == 0) ans = (ans + U[L-1-i][k]) % mod;
			}
		}
	}
	ans = (ans + mod - 1) % mod;

	printf ("%lld\n",ans);
	return 0;
}
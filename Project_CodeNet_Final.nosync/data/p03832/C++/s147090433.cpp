#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 1000+9;
const int MOD = 1000000007;

int n,a,b,c,d,f[N][N],C[N][N],POW[N],REV[N];

inline int read() {
	char c=getchar(); int f=1,ret=0;
	while (c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while (c<='9'&&c>='0') {ret=ret*10+c-'0';c=getchar();}
	return ret * f;
}

inline int Pow(int w, int t) {
	int ret = 1;
	while (t) {
		if (t & 1) ret = (LL)ret * w % MOD;
		w = (LL)w * w % MOD; t >>= 1;
	}
	return ret;
}

int main() {
	n = read(); 
	a = read(); b = read();
	c = read(); d = read();
	for (int i=1;i<N;i++) C[i][1] = i, C[i][0] = 1;
	for (register int i=2;i<N;i++) {
		for (register int j=1;j<N;j++) {
			C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
		}
	}
	POW[0] = 1;
	for (register int i=1;i<N;i++) POW[i] = (LL)POW[i-1] * i % MOD;
	REV[N-1] = Pow(POW[N-1], MOD-2);
	for (register int i=N-2;~i;i--) REV[i] = (LL)REV[i+1] * (i+1) % MOD;
	f[a-1][n] = 1;
	for (register int i=a;i<=b;i++) {
		for (register int j=0;j<=n;j++) {
			if (f[i-1][j]) {
				(f[i][j] += f[i-1][j]) %= MOD;
				if (i*(c-1) > j) continue;
				int w = 1;
				for (register int k=1;k<c;k++) 
					w = (LL)w * C[j-(k-1)*i][i] % MOD;
				for (register int k=c;k<=d;k++) {
					if (i*k <= j) {
						w = (LL)w * C[j-(k-1)*i][i] % MOD;
						(f[i][j-i*k] += ((LL)f[i-1][j] * w % MOD) * REV[k] % MOD) %= MOD;
					} else break;
				}
			}
		}
	}
	printf("%d\n",f[b][0]);
	return 0;
}

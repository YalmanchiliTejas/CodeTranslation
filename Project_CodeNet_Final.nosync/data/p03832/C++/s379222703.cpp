#include<bits/stdc++.h>
#define Mod 1000000007
#define Val(x) (((long long)x) % Mod)
#define maxn 3005
using namespace std;
int C[maxn][maxn],fac[maxn],inv[maxn][maxn];
int Pow(int a,int n) {
	int ret = 1 , base = a;
	while(n > 0) {
		if(n&1)	ret = Val(ret * base);
		base = Val(base * base);
		n >>= 1;
	}
	return ret;
}
int dp1[maxn][maxn];	// dp1[n][b] : # of dividing n people into exactly n / b groups whose size is b
int dp2[maxn][maxn];	// dp2[i][j] : # of dividing i people into some group, all the size of groups is less than or equal to j
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	C[0][0] = 1;
	for(int i=1;i<maxn;i++) {
		C[i][0] = C[i][i] = 1;
		for(int j=1;j<i;j++)
			C[i][j] = Val(C[i-1][j-1] + C[i-1][j]);
	}	

	fac[0] = 1;
	for(int i=1;i<maxn;i++)
		fac[i] = Val(fac[i-1] * i);
	
	for(int i=1;i<maxn;i++) {
		inv[i][1] = Pow(fac[i],Mod-2);
		for(int j=2;j<maxn;j++)
			inv[i][j] = Val(inv[i][j-1] * inv[i][1]);
	}
	
	for(int i=1;i<maxn;i++)
		for(int j=1;j<=i;j++)
			if(i % j == 0)
				dp1[i][j] = Val(Val(fac[i] * inv[j][i/j]) * inv[i/j][1]);
	
	int n,a,b,c,d;
	cin >> n >> a >> b >> c >> d;
	
	fill(dp2[0],dp2[0]+maxn,1);
	for(int i=1;i<=n;i++)
		for(int j=a;j<=b;j++) {
			for(int k=c;k<=d && j*k <= i;k++)
				dp2[i][j] = Val(Val(C[i][j*k] * dp1[j*k][j]) * dp2[i-j*k][j-1] + dp2[i][j]);
			dp2[i][j] = Val(dp2[i][j] + dp2[i][j-1]);
		}
		
	cout << dp2[n][b] << endl;
	return 0;
}

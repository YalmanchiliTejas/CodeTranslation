#include <bits/stdc++.h>

using namespace std;

const int MOD=1e9+7;

long long mem[1005][1005],mem2[1005][1005];
long long nck[1005][1005];
long long fac[1005],invfac[1005];
int n,a,b,c,d;

int mul(long long a,long long b)
{
	a%=MOD; b%=MOD;
	return (1LL*a*b)%MOD;
}

long long poww(long long x,int y)
{
	if(y==0) return 1;
	if(y&1) return mul(poww(x,y-1),x);
	return poww(mul(x,x),y/2);
}

int ways(int n,int m)
{
	if(n==0) return 1;
	if(mem2[n][m]!=-1) return mem2[n][m];
	return mem2[n][m]=mul(nck[n*m][m],ways(n-1,m));
}

int main()
{
	cin >> n >> a >> b >> c >> d;
	fac[0]=1;
	for(int i=1;i<=n;i++) {fac[i]=mul(fac[i-1],i); invfac[i]=poww(fac[i],MOD-2);}
	for(int i=0;i<=n;i++)
	{
		nck[i][0]=1;
		for(int j=1;j<=i;j++)
			nck[i][j]=(nck[i-1][j]+nck[i-1][j-1])%MOD;
	}
	memset(mem2,-1,sizeof mem2);
	mem[b+1][0]=1;
	for(int i=b;i>=a;i--)
	{
		for(int j=n;j>=0;j--)
		{
			//mem[i][j] -> mem[cur][rem];
			mem[i][j]=mem[i+1][j];
			for(int k=c;j-i*k>=0&&k<=d;k++)
			{
				//cout << i << " " << j << " " << k << " : " << mem[i+1][j-i*k] <<" " << nck[j][i*k] << " " << ways(k,i) << endl;
				mem[i][j]+=mul(mul(mul(mem[i+1][j-i*k],nck[j][i*k]),ways(k,i)),invfac[k]);
				mem[i][j]%=MOD;
			}
		}
	}
	cout << mem[a][n] << endl;
}
#include <bits/stdc++.h>
#define uint unsigned long long
#define ll long long
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
inline ll read1()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N=3033;
 
ll qpow(ll a,ll b,ll MOD){ll c=1;for(;b;b>>=1,a=a*a%MOD)if(b&1)c=c*a%MOD;return c;}
 
int n,MOD;
 
int f[N][N],C[N][N];
 
int ans;
 
int main()
{
	scanf("%d%d",&n,&MOD);
 
	f[0][0]=1;
	for(int i=1;i<N;i++)
		for(int j=0;j<N;j++)
			f[i][j]=((ll)f[i-1][j]*j+f[i-1][j-1]+f[i-1][j])%MOD;
	for(int i=0;i<N;i++)C[i][0]=1;
	for(int i=1;i<N;i++)
		for(int j=1;j<N;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
 
	int tmp=qpow(2,n,MOD-1);
	ans=qpow(2,tmp,MOD);
 
	for(int cnt=1;cnt<=n;cnt++)
	{
		int sum=0;
 
		int u=qpow(2,n-cnt,MOD-1);
		int v=qpow(2,n-cnt,MOD);
 
		for(int z=0;z<=cnt;z++)
		{
			int res=f[cnt][z];
			res=(ll)res*qpow(v,z,MOD)%MOD*qpow(2,u,MOD)%MOD;
			sum=(sum+res)%MOD;
		}
		sum=(ll)sum*C[n][cnt]%MOD;
 
		if(cnt&1)ans=(ans-sum)%MOD;
		else ans=(ans+sum)%MOD;
	}
 
	ans=(ans+MOD)%MOD;
	printf("%d\n",ans);
 
	return 0;
}
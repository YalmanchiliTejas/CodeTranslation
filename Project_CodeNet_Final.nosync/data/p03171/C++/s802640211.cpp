#include<bits/stdc++.h>
#define rep(i,k,n) for(int i=k;i<=n;i++)
#define per(i,n,k) for(int i=n;i>=k;i--)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define ll long long
using namespace std;
const int maxn=3005;
ll f[maxn][maxn],a[maxn],n,j;
int main()
{
	scanf("%lld",&n);
	rep(i,1,n) scanf("%lld",a+i),f[i][i]=a[i];
	rep(len,1,n)
	{
		rep(i,1,n)
		{
			j=i+len-1;
			if(j>n) break; else f[i][j]=max(a[i]-f[i+1][j],a[j]-f[i][j-1]);
		}
	}
	printf("%lld",f[1][n]);
	return 0;
}
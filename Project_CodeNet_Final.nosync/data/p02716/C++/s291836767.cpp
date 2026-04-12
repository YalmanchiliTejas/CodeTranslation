
// Problem : F - Select Half
// Contest : AtCoder - AtCoder Beginner Contest 162
// URL : https://atcoder.jp/contests/abc162/tasks/abc162_f
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

//QWsin
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define out(i,u) for(int i=first[u];i!=-1;i=nxt[i])
#define repvc(i,vc) for(int i=0,Sz=vc.size();i<Sz;++i)
using namespace std;
inline int read()
{
	char ch=getchar();int ret=0,f=1;
	while(ch<'0' || ch>'9') {if(ch=='-')f=-1;ch=getchar();}
	for(;ch>='0' && ch<='9';ch=getchar()) ret=ret*10+ch-'0';
	return ret*f;
}

typedef long long ll;
const int INF=1<<30;

const int maxn=200000+10;
int a[maxn];
ll dp[maxn][3];

ll max(ll x,ll y,ll z){return max(max(x,y),z);}

int main()
{
	int n;cin>>n;
	rep(i,1,n) cin>>a[i];

	rep(i,0,n) rep(j,0,2) dp[i][j]=-(1ll<<60);
	dp[0][0]=0;
	dp[1][0]=a[1];
	dp[2][1]=a[2];
	dp[3][2]=a[3];
	rep(i,3,n){
		dp[i][0]=dp[i-2][0]+a[i];
		dp[i][1]=max(dp[i][1],dp[i-2][1]+a[i]);
		if(i>3) dp[i][1]=max(dp[i][1],dp[i-3][0]+a[i]);
		dp[i][2]=max(dp[i][2],dp[i-2][2]+a[i]);
		if(i>3) dp[i][2]=max(dp[i][2],dp[i-3][1]+a[i]);
		if(i>4) dp[i][2]=max(dp[i][2],dp[i-4][0]+a[i]);
	}
	if(n&1)cout<<max(dp[n-2][0],dp[n-1][1],dp[n][2])<<endl;
	else cout<<max(dp[n-1][0],dp[n][1])<<endl;
	// rep(j,0,2){
		// rep(i,1,n){
			// printf("%I64d%c",dp[i][j],i==n?'\n':' ');
		// }
	// }
	return 0;
}

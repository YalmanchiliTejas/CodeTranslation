#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=111,mod=1000000007,inv2=500000004;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
template<typename T>
inline void read(T &x){
	x=0;
	char ch=getchar();bool f=false;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	if(f) x=-x;
}
int n,h[maxn],dp[maxn][maxn][2][2][2],mn[maxn][maxn],tmp[2][2][2],ans;
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
void go_lower(int f[][2][2],int cnt){
	if(!cnt) return;
	int g[2][2][2];
	MEM(g,0);
	FOR(a,0,1) FOR(b,0,1) FOR(c,0,1) if(c){
		if(cnt%2==0) g[a][b][c]=f[a][b][c];
		else g[a^1][b^1][c]=f[a][b][c];
	}
	else{
		g[a][b][c]=(g[a][b][c]+1ll*f[a][b][c]*qpow(2,cnt-1))%mod;
		g[a^1][b^1][c]=(g[a^1][b^1][c]+1ll*f[a][b][c]*qpow(2,cnt-1))%mod;
	}
	FOR(a,0,1) FOR(b,0,1) FOR(c,0,1) f[a][b][c]=g[a][b][c];
}
void merge(int f[][2][2],int g[][2][2]){
	int h[2][2][2];
	MEM(h,0);
	FOR(a,0,1) FOR(b,0,1) FOR(c,0,1) FOR(d,0,1) FOR(e,0,1) FOR(f_,0,1){
		int to=c|f_|(b==d);
		h[a][e][to]=(h[a][e][to]+1ll*f[a][b][c]*g[d][e][f_])%mod;
	}
	FOR(a,0,1) FOR(b,0,1) FOR(c,0,1) f[a][b][c]=h[a][b][c];
}
void dfs(int l,int r){
	if(l>r) return;
	if(l==r){
		dp[l][r][0][0][0]=dp[l][r][1][1][0]=1;
		return;
	}
	int last=l-1;
	FOR(i,l,r) if(h[i]==mn[l][r]){
		if(last+1<=i-1){
			dfs(last+1,i-1);
			go_lower(dp[last+1][i-1],mn[last+1][i-1]-mn[l][r]);
			if(last==l-1){
				FOR(a,0,1) FOR(b,0,1) FOR(c,0,1) dp[l][r][a][b][c]=dp[last+1][i-1][a][b][c];
			}
			else merge(dp[l][r],dp[last+1][i-1]);
		}
		if(i==l) FOR(a,0,1) FOR(b,0,1) FOR(c,0,1) dp[l][r][a][b][c]=tmp[a][b][c]; 
		else merge(dp[l][r],tmp);
		last=i;
	}
	if(last!=r){
		dfs(last+1,r);
		go_lower(dp[last+1][r],mn[last+1][r]-mn[l][r]);
		if(last==l-1){
			FOR(a,0,1) FOR(b,0,1) FOR(c,0,1) dp[l][r][a][b][c]=dp[last+1][r][a][b][c];
		}
		else merge(dp[l][r],dp[last+1][r]);
	}
}
int main(){
	read(n);
	FOR(i,1,n) read(h[i]);
	FOR(i,1,n){
		mn[i][i]=h[i];
		FOR(j,i+1,n) mn[i][j]=min(mn[i][j-1],h[j]);
	}
	tmp[0][0][0]=tmp[1][1][0]=1;
	dfs(1,n);
	go_lower(dp[1][n],mn[1][n]-1);
	FOR(a,0,1) FOR(b,0,1) FOR(c,0,1) ans=(ans+dp[1][n][a][b][c])%mod;
	printf("%d\n",ans);
	return 0;
}
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
template <class T>
inline void rd(T &x) {
	x=0; char c=getchar(); int f=1;
	while(!isdigit(c)) { if(c=='-') f=-1; c=getchar(); }
	while(isdigit(c)) x=x*10-'0'+c,c=getchar(); x*=f;
}
const int N=110,mod=1e9+7;
inline int Pow(int x,int y) { int res=1; for(;y;y>>=1,x=x*(ll)x%mod) if(y&1) res=res*(ll)x%mod; return res; }
int f[N][N][2],vis[N][N],h[N],minv[N][N],n;
void sol(int l,int r) {
	if(vis[l][r]) return;
	vis[l][r]=1;
	minv[l][r]=1e9;
	for(int i=l;i<=r;++i) minv[l][r]=min(minv[l][r],h[i]);
	int lst=l-1,tot=0;
	f[l][r][0]=f[l][r][1]=1;
	for(int i=l;i<=r+1;++i) if(h[i]==minv[l][r]||i==r+1) {
		int L=lst+1,R=i-1; lst=i;
		if(L<=R) {
			sol(L,R);
			f[l][r][0]=f[l][r][0]*(ll)f[L][R][0]%mod*Pow(2,minv[L][R]-minv[l][r]-1)%mod;
			f[l][r][1]=f[l][r][1]*(ll)(f[L][R][0]*(ll)Pow(2,minv[L][R]-minv[l][r])%mod+f[L][R][1])%mod;
			tot+=R-L+1;
		}
	}
	f[l][r][0]=f[l][r][0]*2ll%mod;
	f[l][r][1]=(f[l][r][1]*(ll)Pow(2,r-l+1-tot)%mod-f[l][r][0])%mod;
}		
	
int main() {
	rd(n);
	for(int i=1;i<=n;++i) rd(h[i]);
	sol(1,n);
	int ans=(f[1][n][0]*(ll)Pow(2,minv[1][n]-1)%mod+f[1][n][1])%mod;
	printf("%d",(ans+mod)%mod);
	return 0;
}
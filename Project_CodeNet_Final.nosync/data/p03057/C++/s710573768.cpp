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
const int N=2e5+10,mod=1e9+7;
inline void Dec(int &x,int y) { x-=y; if(x<0) x+=mod; }
inline void Add(int &x,int y) { x+=y; if(x>=mod) x-=mod; }
char S[N];
int n,m,f[N];
int main() {
	rd(n),rd(m);
	scanf("%s",S+1);
	char c=S[1];
	int p=1,r=1,L=m;
	
	while(r<=m&&S[r]==c) r++;
	if(r==m+1) {
		if(n==2) { printf("3\n"); return 0; }
		f[0]=1,f[1]=2;
		for(int i=2;i<=n;++i) f[i]=(f[i-1]+f[i-2])%mod;
		printf("%d\n",(f[n-3]+f[n-1])%mod);
		return 0;
	}
	
	L=min(L,(r-p)|1);	
	p=r;
	while(p<=m&&S[p]!=c) p++;
	
	while(1) {
		r=p;
		while(r<=m&&S[r]==c) r++;
		if(r>m) break;
		if((r-p)&1) L=min(L,r-p);
		p=r;
		while(p<=m&&S[p]!=c) p++;
	}
	int sum[2]={0,0};
	f[1]=1,sum[1]=1;
	for(int i=2;i<=n;++i) {
		f[i]=sum[i&1];
		if(i-L-1>=1) Dec(sum[i&1],f[i-L-1]);
		Add(sum[i&1],f[i]);
	}
	int ans=0;
	for(int i=1;i<=n;++i) {
		if(n-i>L||!((n-i)&1)) continue;
		Add(ans,f[i]*(ll)(n-i+1)%mod);
	}
	printf("%d",ans);
	return 0;
}
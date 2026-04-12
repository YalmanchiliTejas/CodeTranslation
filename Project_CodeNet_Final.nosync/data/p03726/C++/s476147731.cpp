#include<bits/stdc++.h>
using namespace std;
#define REP(i,st,ed) for(register int i=st,i##end=ed;i<=i##end;++i)
#define DREP(i,st,ed) for(register int i=st,i##end=ed;i>=i##end;--i)
typedef long long ll;
template<typename T>inline bool chkmin(T &x,T y){return (y<x)?(x=y,1):0;}
template<typename T>inline bool chkmax(T &x,T y){return (y>x)?(x=y,1):0;}
inline int read(){
	int x;
	char c;
	int f=1;
	while((c=getchar())!='-' && (c>'9' || c<'0'));
	if(c=='-') f=-1,c=getchar();
	x=c^'0';
	while((c=getchar())>='0' && c<='9') x=(x<<1)+(x<<3)+(c^'0');
	return x*f;
}
inline ll readll(){
	ll x;
	char c;
	int f=1;
	while((c=getchar())!='-' && (c>'9' || c<'0'));
	if(c=='-') f=-1,c=getchar();
	x=c^'0';
	while((c=getchar())>='0' && c<='9') x=(x<<1ll)+(x<<3ll)+(c^'0');
	return x*f;
}
const int maxn=1e6+10;
vector<int> G[maxn];
int ans;
bool dfs(int x,int ff){
	bool flag=0;
	for(auto v:G[x]) if(v!=ff){
		bool b=dfs(v,x);
		if(flag && b) ans=1;
		flag|=b;
	}
	return flag^1;
}
int main(){
	int n=read();
	REP(i,1,n-1){
		int x=read(),y=read();
		G[x].push_back(y),G[y].push_back(x);
	}
	ans|=dfs(1,0);
	printf("%s\n",ans?"First":"Second");
	return 0;
}

//抄的hzw的 
#include <bits/stdc++.h>
#define pb push_back
#define cmin(a,b) (a>b?a=b:a)
#define cmax(a,b) (a<b?a=b:a)
#define mem(a,k) memset(a,k,sizeof(a))
#define lop(i,s,t) for(int i=s;i<(t);++i)
#define rep(i,s,t) for(int i=s;i<=(t);++i)
#define dec(i,s,t) for(int i=s;i>=(t);--i)
#define fore(i,v) for(int i=g[v],d=es[i].d;i;i=es[i].nxt,d=es[i].d)
using namespace std;
 
#define Pr(f,...) fprintf(stderr,f,##__VA_ARGS__),fflush(stderr)
 
typedef long long ll;
 
template<typename T>
void read(T &x){
	x=0; 
	char c;
	for(c=getchar();!isdigit(c);c=getchar()); 
	for(;isdigit(c);c=getchar())x=x*10+c-'0'; 
}
 
const int N=1e5+50;
 
int n;
bool fail,mat[N];
vector<int> g[N]; 
 
void dfs(int v,int p){
	for(int d:g[v])if(d!=p){
		dfs(d,v); 
		if(!mat[d]&&!mat[v]){
			mat[v]=true;
			mat[d]=true;
		}else if(!mat[d]&&mat[v]){
			fail=true;
		}
	}
}
 
int main(int argc,char *argv[]){
#ifdef CURIOUSCAT
#endif
	read(n); 
	rep(i,1,n-1){
		int u,v; 
		read(u),read(v); 
		g[v].pb(u); 
		g[u].pb(v); 
	}
	dfs(1,0); 
	fail|=!mat[1]; 
	puts(fail?"First":"Second"); 
	return 0;
}
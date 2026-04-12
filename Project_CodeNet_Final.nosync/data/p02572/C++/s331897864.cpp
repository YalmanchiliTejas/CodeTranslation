#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define pa pair<int,int>
#define mod 1000000007
#define ll long long
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define cl(x) memset(x,0,sizeof x)
#ifdef Devil_Gary
#define bug(x) cout<<(#x)<<" "<<(x)<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define bug(x)
#define debug(...)
#endif

const int INF = 0x7fffffff;
const int N=1e5+5;
/*
char *TT,*mo,but[(1<<15)+2];
#define getchar() ((TT==mo&&(mo=(TT=but)+fread(but,1,1<<15,stdin),TT==mo))?-1:*TT++)//*/
inline int read(){
    int x=0,rev=0,ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')rev=1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return rev?-x:x;
}/*
struct Edge{
	int nxt,v;
//	int w;
//	int id;
}e[N<<1];
void add(int u,int v){
	e[++tot].v=v,e[tot].nxt=head[u],head[u]=tot;
	e[++tot].v=u,e[tot].nxt=head[v],head[v]=tot;
}*/

int main(){
#ifdef Devil_Gary
    freopen("in.txt","r",stdin);
//  freopen("out.txt","w",stdout);
#endif
	ll n=read(),ans=0,s=0;
	for(int i=1;i<=n;i++) {
		ll x;
		cin>>x;
		(ans+=s*x%mod)%=mod;
		(s+=x)%=mod;
	}
	cout<<ans<<endl;
	return 0;
}

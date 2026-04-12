#include<iostream>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<cstdio>
#include<cctype>
#include<cassert>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<iomanip>
#include<utility>
#include<functional> 
using namespace std;
#define mp make_pair
#define pb push_back
#define pf push_front
#define X first
#define Y second
#define rg register
#define il inline
#define lch(x) ((x)<<1)
#define rch(x) ((x)<<1^1)
#define rep0(i,n) for(register int (i)=0;(i)<(n);++(i))
#define rep(i,st,ed) for(register int (i)=(st);(i)<=(ed);++(i))
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double dbl;
typedef long double ldb;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T> il T qmin(const T a,const T b) {return a<b?a:b;}
template<typename T> il T qmax(const T a,const T b) {return a>b?a:b;}
template<typename T> il void getmin(T &a,const T b) {if(a>b) a=b;}
template<typename T> il void getmax(T &a,const T b) {if(a<b) a=b;}
il void fileio(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

const int inf=(int)1e9+7;
const ll linf=(ll)1e17+7;
const int N=1e5+7,M=N<<1;

int v[M],nxt[M];
int head[N];
bool used[N];
int n,tot;

il void addedge(int p,int x,int y){
	v[p]=y,nxt[p]=head[x],head[x]=p;
}

il bool chk(int u,int p){
	for(int e=head[u];e;e=nxt[e]){
		if(v[e]==p) continue;
		if(!chk(v[e],u)) return false;
		if(!used[v[e]]){
			if(used[u]) return false;
			used[u]=used[v[e]]=true;
		}
	}
	return true;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<n;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		addedge(lch(i),x,y);
		addedge(rch(i),y,x);
	}
	if(chk(1,0)&&used[1]) puts("Second");
	else puts("First");
	return 0;
} 
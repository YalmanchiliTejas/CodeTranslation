#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <locale>
#include <numeric>
#include <new>
#include <stdexcept>
#include <limits>
#include <valarray>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <bitset>
#include <algorithm>
#include <functional>
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=1e9+7;
const ll INFL=1LL<<60;
vector<pii> G1[100005],G2[100005];
ll dis[100005];
bool fin[100005];
ll dp1[100005],dp2[100005];
vector<int> ord;
ll sqrl(ll x){
	x%=INF;
	return x*x%INF;
}
void inc(ll& u,ll v){
	u+=v;
	u%=INF;
}
void dijkstra(int s,int t){
	memset(fin,false,sizeof(fin));
	rep1(k,100000)dis[k]=INFL;
	priority_queue<pair<ll,int> > Q;
	dis[s]=0LL;
	Q.push(MP(0LL,s));
	while(!Q.empty()){
		int v=Q.top().second;
		Q.pop();
		if(fin[v])continue;
		ord.push_back(v);
		fin[v]=true;
		rep(k,G1[v].size()){
			int u=G1[v][k].first,cd=G1[v][k].second;
			if(dis[v]+cd<dis[u]){
				dis[u]=dis[v]+cd;
				Q.push(MP(-dis[u],u));
			}
		}
	}
}
int main(){
	int n,m,s,t;
	scanf("%d%d%d%d",&n,&m,&s,&t);
	rep(k,m){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		G1[u].push_back(MP(v,w));
		G1[v].push_back(MP(u,w));
	}
	dijkstra(s,t);
	rep1(i,n)rep(j,G1[i].size())
	if(dis[i]+G1[i][j].second==dis[G1[i][j].first])
	G2[i].push_back(G1[i][j]);
	dp1[s]=1LL;
	rep(i,ord.size()){
		int cv=ord[i];
		rep(j,G2[cv].size())
		inc(dp1[G2[cv][j].first],dp1[cv]);
	}
	dp2[t]=1LL;
	for(int i=ord.size()-1;i>=0;i--){
		int cv=ord[i];
		rep(j,G2[cv].size())
		inc(dp2[cv],dp2[G2[cv][j].first]);
	}
	ll tot=0LL;
	rep1(i,n){
		if(dis[i]+dis[i]==dis[t])inc(tot,sqrl(dp1[i]*dp2[i]));
		rep(j,G2[i].size()){
			int cu=i,cv=G2[i][j].first;
			if(dis[cu]<dis[t]-dis[cu]&&dis[t]-dis[cv]<dis[cv])inc(tot,sqrl(dp1[cu]*dp2[cv]));
		}
	}
	tot=(dp1[t]*dp2[s]-tot)%INF;
	if(tot<0)tot+=INF;
	printf("%lld\n",tot);
	return 0;
}
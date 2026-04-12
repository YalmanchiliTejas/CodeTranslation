#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <bitset>     //UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>        //do setprecision
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double

const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;
const int mod=1000000007;
LL add(LL a,LL b){
  return (a+b)%mod;
}

LL sub(LL a,LL b){
  return (a+mod-b)%mod;
}

LL mul(LL a,LL b){
  return ((a % mod) * (b % mod)) % mod;
}

struct edge
{
  int to, cost;
};
typedef vector< vector < edge > > Graph;
int dp[100010]={};
int dpr[100010]={};
template< typename T = LL >
vector< T > Dijkstra(Graph &g, int s,int rev)
{
  typedef pair< T, int > Pi;
	//cout<<g.size()<<" "<<rev<<endl;
  vector< T > min_cost(g.size(), numeric_limits< T >::max());
  priority_queue< Pi, vector< Pi >, greater< Pi > > que;//cost,from
  que.emplace(0, s);
  min_cost[s] = 0;
  while(!que.empty()) {
    Pi p = que.top();
    que.pop();
    if(p.first > min_cost[p.second]) continue;
		//cout<<p.second<<endl;
    for(auto &e : g[p.second]) {
      if(p.first + e.cost > min_cost[e.to]) continue;
			//*
			if(p.first + e.cost == min_cost[e.to]){
				if(rev==0)dp[e.to]=add(dp[p.second],dp[e.to]);
				else dpr[e.to]=add(dpr[p.second],dpr[e.to]);
				continue;
			}else {
				if(rev==0)dp[e.to]=dp[p.second];
				else dpr[e.to]=dpr[p.second];
			}//*/
      min_cost[e.to] = p.first + e.cost;
      que.emplace(min_cost[e.to], e.to);
    }
		//cout<<p.second<<endl;
  }
  return (min_cost);
}

int main(){
	int n,m,s,t;
	vector< vector<edge> > g;
	g.resize(100010);
	cin>>n>>m>>s>>t;
	int u,d,v;
	//cout<<"test"<<endl;
	FOR(i,0,m){
		cin>>u>>v>>d;
		edge ee;
		ee.to=u;
		ee.cost=d;
		g[v].push_back(ee);
		ee.to=v;
		ee.cost=d;
		g[u].push_back(ee);
	}
	//cout<<"test"<<endl;
	dp[s]=1;
	vector <LL> mc=Dijkstra(g, s, 0);
	dpr[t]=1;
	vector <LL> mcr=Dijkstra(g, t, 1);
	/*
	cout<<" tes:"<<dp[t]<<endl;
	cout<<" tesr:"<<dpr[s]<<endl;
	cout<<" mcr:"<<mcr[s]<<endl;//*/

	LL p=dp[t];
	p=mul(p,p);
	//cout<<p<<endl;
	FORQ(i,1,n){
		if(mc[t]%2==0&&mc[i]==mc[t]/2){
			LL pp=mul(dp[i],dpr[i]);
			p=sub(p,mul(pp,pp));
		}
		//cout<<p<<endl;
		for(auto &e : g[i]){
			int toto=e.to,costco=e.cost;
			if(mc[i]+costco+mcr[toto]!=mc[t])continue;
			//cout<<"edge:"<<i<<" "<<toto<<endl;
			if(mc[i]*2<mc[t]&&mc[toto]*2>mc[t]){
				//cout<<"on edge"<<" "<<endl;
				LL pp=mul(dp[i],dpr[toto]);
				p=sub(p,mul(pp,pp));
			}
		}
		//cout<<p<<endl;
	}
	cout<<p <<endl;

    return 0;
}

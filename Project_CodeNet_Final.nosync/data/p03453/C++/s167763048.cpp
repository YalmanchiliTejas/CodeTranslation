#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <queue>
#include <deque>
#include <iomanip>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>

#define FOR(i,n) for(int i=0;i<n;i++)
#define FORE(i,a,b) for(int i=a;i<=b;i++)
#define ll long long 
//#define int long long
#define ld long double
#define vi vector<ll>
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define iii pair<int,ii>
#define il pair<int,ll>
#define pll pair<ll,ll>
#define _path pair<ll,pair<ll,int> > // length, numlength, node,we also take numlength to be negetive so that paths with the same length is sorted by descending order of number of such path. this is essential otherwise it will lead to undercounting of number of same length paths
#define vv vector
//#define endl '\n'
using namespace std;
const int MAXN = 100*1000 + 5;
const ll INF = 1e17;
const ll MOD = 1e9 +7;

vv<il> g[MAXN];
int n;
int S;
int T;

ll dist[2][MAXN];
ll numDist[2][MAXN];
bool vis[MAXN];

void dijk(int source){
	priority_queue<_path, vv<_path>, greater<_path> > pq;
	pq.push({0,{-1,source}});
	
	bool x = source == S;
	FOR(i,n)dist[x][i] = INF;
	FOR(i,n)vis[i] = 0;
	dist[x][source] = 0;
	numDist[x][source] = 1;
	
	while(!pq.empty()){
		auto item = pq.top();pq.pop();
		if(dist[x][item.ss.ss] < item.ff)continue;
		if(vis[item.ss.ss])continue;
		vis[item.ss.ss] = 1;

		for(auto e: g[item.ss.ss]){
			if(dist[x][e.ff] < item.ff + e.ss)continue;
			if(dist[x][e.ff] == item.ff + e.ss){
				numDist[x][e.ff] += numDist[x][item.ss.ss];
				numDist[x][e.ff] %= MOD;
			}else{
				dist[x][e.ff] = item.ff + e.ss;
				numDist[x][e.ff] = numDist[x][item.ss.ss];
				pq.push(make_pair(dist[x][e.ff],make_pair(numDist[x][item.ss.ss],e.ff)));				
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int m;
	cin >> n >> m;
	cin >> S >> T;
	S--;
	T--;
	vv<pair<ii,ll> > allEdges;
	FOR(i,m){
		int a,b;ll c;cin >> a >> b >> c;a--;b--;
		g[a].pb({b,c});
		g[b].pb({a,c});
		allEdges.pb({{a,b},c});
	}
	dijk(S);
	dijk(T);
	FOR(i,n){
		//cout << dist[0][i] << " " << dist[1][i] << " " << numDist[0][i] << " " << numDist[1][i] << endl;
	}

	ll stp = numDist[1][T];
	ll tot = (stp*stp)%MOD;
	
	// lets subtract for all the nodes first. 
	FOR(i,n){
		if(dist[0][i] + dist[1][i] == dist[1][T] and dist[0][i] == dist[1][i]){
			ll xx =(numDist[0][i]*numDist[1][i])%MOD; 
			tot -= (xx*xx)%MOD;
			tot %= MOD;
		}
	}
	
	for(auto e: allEdges){
		if(min(dist[0][e.ff.ff],dist[0][e.ff.ss]) + min(dist[1][e.ff.ff],dist[1][e.ff.ss]) + e.ss != dist[0][S]){
			continue;

		}
		if(dist[0][e.ff.ff] > dist[0][e.ff.ss])swap(e.ff.ff,e.ff.ss);
		pll range1 = {dist[0][e.ff.ff],dist[0][e.ff.ss]};
	
		pll range2 = {dist[1][e.ff.ss],dist[1][e.ff.ff]};
		//cout << range1.ff << " " << range1.ss << " " << range2.ff << " " << range2.ss << endl;
		if(range1.ss <= range2.ff or range1.ff >= range2.ss){

		}else{
			// they intersect;
			ll xx = (numDist[0][e.ff.ff]*numDist[1][e.ff.ss])%MOD;
			tot -= (xx*xx)%MOD;
			tot %= MOD;
		}
	}
	tot %= MOD;
	tot += MOD;
	tot %= MOD;
	cout << tot << endl;

	return 0;
}
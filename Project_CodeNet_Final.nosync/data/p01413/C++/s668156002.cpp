#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <deque>
#include <complex>
#include <string>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <valarray>
#include <iterator>
using namespace std;
typedef long long int ll;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();i++)
#define ALL(container) container.begin(), container.end()
#define RALL(container) container.rbegin(), container.rend()
#define SZ(container) ((int)container.size())
#define mp(a,b) make_pair(a, b)
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"["; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"]"; return os;
}
template<class T> ostream& operator<<(ostream &os, const set<T> &t) {
os<<"{"; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"}"; return os;
}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}

const int INF = 1<<28;
const double EPS = 1e-8;
const int MOD = 1000000007;


int N, M, W, T;

int dp[1<<7][8];
int g[7][7];


ll napsack(vector<pii> items, int lim){
	int n = items.size();
	vector<ll> dp(lim+1, -(1LL<<60));
	dp[0] = 0;
	REP(i, n)REP(j, lim-items[i].first+1) chmax(dp[j+items[i].first], dp[j] + items[i].second);
	return *max_element(ALL(dp));
}

main(){
	map<string, int> idx;
	vector<pii> items;
	cin >> N >> M >> W >> T;
	REP(i, M){
		string s;
		int v, p;
		cin >> s >> v >> p;
		idx[s] = i;
		items.emplace_back(v, p);
	}
	vector<pii> place;
	vector< vector<pii> > town(N);
	REP(i, N){
		int l, x, y;
		cin >> l >> x >> y;
		place.emplace_back(x, y);
		REP(j, l){
			string s;
			int p;
			cin >> s >> p;
			int v = items[idx[s]].first;
			p = items[idx[s]].second - p;
			if(p <= 0) continue;
			town[i].emplace_back(v, p);
		}
	}
	REP(i, N)REP(j, N) g[i][j] = abs(place[i].first - place[j].first) + abs(place[i].second - place[j].second);
	memset(dp, 63, sizeof(dp));
	dp[0][0] = 0;
	vector<int> dist(1<<N, INF);
	REP(i, 1<<N)REP(j, N)REP(k, N){
		int oc = abs(place[k].first) + abs(place[k].second);
		int c = dp[i][j] + (i ? g[j][k] : oc);
		chmin(dp[i|(1<<k)][k], c);
		chmin(dist[i|(1<<k)], c+oc);
	}
	vector<pii> items2;
	REP(i, 1<<N){
		if(!i) continue;
		vector<pii> d;
		REP(j, N) if((i>>j)&1) d.insert(d.end(), town[j].begin(), town[j].end());
		items2.emplace_back(dist[i], napsack(d, W));
	}
	cout << napsack(items2, T) << endl;
	return 0;
}
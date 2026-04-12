#include <bits/stdc++.h>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
typedef pair<LL, LL> PLL;

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define FF first
#define SS second
template<class S, class T>
istream& operator>>(istream& is, pair<S,T>& p){
  return is >> p.FF >> p.SS;
}

const double EPS = 1e-10;
const double PI  = acos(-1.0);
const LL MOD = 1e9+7;
const int INF = 1e9;

// xs = <weight, value>
LL knapsack(vector<PLL>& xs, LL W){
  int N = SZ(xs);
  LL dp[W+1];
  fill(dp, dp+W+1, -1);
  dp[0] = 0;
  REP(i,N){
	for(int w=xs[i].FF;w<=W;++w)
	  if(dp[w-xs[i].FF] < 0) continue;
	  else dp[w] = max(dp[w], dp[w-xs[i].FF]+xs[i].SS);
  }

  LL res = 0;
  for(int i=0;i<=W;++i) res = max(res, dp[i]);
  return res;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int CITY, ITEM, W, T; cin >> CITY >> ITEM >> W >> T;
  map<string,int> index;
  // weight, sell price
  vector<PLL> items(ITEM);
  REP(i,ITEM){
	string s; int w, p; cin >> s >> w >> p;
	items[i] = MP(w,p);
	index[s] = i;
  }

  // x, y, buy prices
  vector<tuple<int,int,VI>> citys(CITY);
  REP(i,CITY){
	int L, x, y; cin >> L >> x >> y;
	get<0>(citys[i]) = x;
	get<1>(citys[i]) = y;
	VI& buf = get<2>(citys[i]);
	buf.assign(ITEM, INF);
	REP(i,L){
	  string s; int p; cin >> s >> p;
	  buf[index[s]] = p;
	}
  }

  // city bit, min_time
  map<int,int> vis;
  VI perm(CITY);
  REP(i,CITY) perm[i] = i;
  do{
	int t = 0, bit = 0;
	int px = 0, py = 0;
	REP(i,CITY){
	  int idx = perm[i];
	  bit |= 1<<idx;
	  int x = get<0>(citys[idx]);
	  int y = get<1>(citys[idx]);
	  t += abs(px - x) + abs(py - y);
	  int ret_t = t + abs(x) + abs(y);
	  if(ret_t > T) break;
	  px = x, py = y;
	  if(!vis.count(bit))
		vis[bit] = ret_t;
	  else
		vis[bit] = min(vis[bit], ret_t);
	}
  }while(next_permutation(ALL(perm)));

  // time, benefit
  map<LL,LL> route;
  for(auto& p: vis){
	vector<PLL> knap(ITEM);
	REP(i,ITEM) knap[i] = MP(items[i].FF, 0);
	REP(i,CITY){
	  if(p.FF>>i&1)
		REP(j,ITEM) knap[j].SS = max(knap[j].SS, items[j].SS - get<2>(citys[i])[j]);
	}
	route[p.SS] = max(route[p.SS], knapsack(knap,W));
  }

  vector<PLL> knap(ALL(route));
  cout << knapsack(knap, T) << endl;
  
  return 0;
}
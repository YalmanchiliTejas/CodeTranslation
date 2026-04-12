#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <tuple>
#include <cstdio>
#include <bitset>
#include <sstream>
#include <iterator>
#include <numeric>
#include <map>
#include <cstring>
#include <set>
#include <functional>
#include <iomanip>

using namespace std;

#define DEBUG_ //!!提出時にコメントアウト!!
#ifdef DEBUG_
	#define dump(x)  cerr << #x << " = " << (x) << endl;
#else
	#define dump(x)  ;
#endif

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define SZ(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back

//#define int long long

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

template< typename T >
struct edge {
  int src, to;
  T cost;
  edge(int to, T cost) : src(-1), to(to), cost(cost) {}
  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}
  edge &operator=(const int &x) {
    to = x;
    return *this;
  }
  operator int() const { return to; }
};
template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;

template< typename T >
T prim(WeightedGraph< T > &g) {
using Pi = pair< T, int >;

T total = 0;
vector< bool > used(g.size(), false);
priority_queue< Pi, vector< Pi >, greater< Pi > > que;
que.emplace(0, 0);
while(!que.empty()) {
    auto p = que.top();
    que.pop();
    if(used[p.second]) continue;
    used[p.second] = true;
    total += p.first;
    for(auto &e : g[p.second]) {
    que.emplace(e.cost, e.to);
    }
}
return total;
}

template <typename T>
std::string printVector(const std::vector<T> &data)
{
    std::stringstream ss;
    std::ostream_iterator<T> out_it(ss, ", ");
    ss << "[";
    std::copy(data.begin(), data.end() - 1, out_it);
    ss << data.back() << "]";
    return ss.str();
}

const int MOD = 1e9+7;
const LL LINF = 1001002003004005006ll;
const int INF = 1001001001;

signed main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<PII> xset(N);
    vector<PII> yset(N);
    WeightedGraph<int> g(N);
    REP(i,N){
        int x,y; cin >> x >> y;
        xset[i] = PII(x,i);
        yset[i] = PII(y,i);
    }
    sort(xset.begin(),xset.end());
    sort(yset.begin(),yset.end());
    for(int i = 0; i < N; i++){
        int nodex = xset[i].second;
        int nodey = yset[i].second;
        if(i == 0){
            int nodex_n = xset[i+1].second;
            int distx = abs(xset[i].first - xset[i+1].first);
            int nodey_n = yset[i+1].second;
            int disty = abs(yset[i].first - yset[i+1].first);

            g[nodex].eb(nodex_n,distx);
            g[nodex_n].eb(nodex,distx);
            g[nodey].eb(nodey_n,disty);
            g[nodey_n].eb(nodey,disty);
        }
        else if(i == N-1){
            int nodex_n = xset[i-1].second;
            int distx = abs(xset[i].first - xset[i-1].first);
            int nodey_n = yset[i-1].second;
            int disty = abs(yset[i].first - yset[i-1].first);

            g[nodex].eb(nodex_n,distx);
            g[nodex_n].eb(nodex,distx);
            g[nodey].eb(nodey_n,disty);
            g[nodey_n].eb(nodey,disty);
        }
        else{
            int nodex_n = xset[i+1].second;
            int nodex_p = xset[i-1].second;
            int distx_n = abs(xset[i].first - xset[i+1].first);
            int distx_p = abs(xset[i].first - xset[i-1].first);

            int nodey_n = yset[i+1].second;
            int nodey_p = yset[i-1].second;
            int disty_n = abs(yset[i].first - yset[i+1].first);
            int disty_p = abs(yset[i].first - yset[i-1].first);

            g[nodex].eb(nodex_n,distx_n);
            g[nodex_n].eb(nodex,distx_n);
            g[nodex].eb(nodex_p,distx_p);
            g[nodex_p].eb(nodex,distx_p);

            g[nodey].eb(nodey_n,disty_n);
            g[nodey_n].eb(nodey,disty_n);
            g[nodey].eb(nodey_p,disty_p);
            g[nodey_p].eb(nodey,disty_p);

        }
    }
    cout << prim(g) << endl;

}
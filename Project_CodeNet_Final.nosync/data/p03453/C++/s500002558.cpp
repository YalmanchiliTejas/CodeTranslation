#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <iomanip>
#include <cmath>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>


//using namespace __gnu_pbds;
using namespace std;


typedef long long ll;
typedef long double ld;

/*
typedef
tree<
  int, // Data type
  null_type,
  less<int>, // Comparator function for the data type
  rb_tree_tag,
  tree_order_statistics_node_update>
ordered_set;
*/

const ll MOD_CONST = 1000000007ll;


ll modSum(ll a, ll b, ll MOD = MOD_CONST) {
  return ((a % MOD) + (b % MOD)) % MOD;
}


ll modSubtract(ll a, ll b, ll MOD = MOD_CONST) {
  return (((a % MOD) - (b % MOD)) + MOD + MOD) % MOD;
}


ll modProd(ll a, ll b, ll MOD = MOD_CONST) {
  return ((a % MOD) * (b % MOD)) % MOD;
}


ll getPowMod(ll x, ll e, ll MOD = MOD_CONST) {
  if (e == 0) return 1;
  if (e % 2 == 0) {
    ll tmp = getPowMod(x, e/2, MOD);
    return modProd(tmp, tmp, MOD);
  } else {
    ll tmp = getPowMod(x, e-1, MOD);
    return modProd(tmp, x, MOD);
  }
}


ll getPow(ll x, ll e) {
  if (e == 0) return 1;
  if (e % 2 == 0) {
    ll tmp = getPow(x, e/2);
    return tmp * tmp;
  } else {
    ll tmp = getPow(x, e-1);
    return tmp * x;
  }
}


ll getInverse(ll x, ll MOD = MOD_CONST) {
  return getPowMod(x, MOD-2, MOD);
}


bool isEven(ll x) {
  ll tmp = ((x % 2) + 2) % 2;
  return tmp == 0;
}


ll getSumOfDigitsInBase(ll n, ll b) {
  ll ret = 0;
  while (n > 0) {
    ret += n % b;
    n /= b;
  }
  return ret;
}


vector<int> getKMP(string &s) {
  int len = (int)s.size();
  vector<int> ret (len, 0);
  for (int i = 1 ; i < len ; i++) {
    int at = ret[i-1];
    while (at > 0 && s[i] != s[at]) {
      at = ret[at-1];
    }
    if (s[i] == s[at]) {
      at++;
    }
    ret[i] = at;
  }
  return ret;
}


string getSubstring(string &s, int from, int to) {
  int l = to-from+1;
  if (l <= 0) {
    return "";
  }
  return s.substr(from, l);
}

ll gcd(ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}


pair<ll, ll> getIntersectingRange(ll a1, ll b1, ll a2, ll b2) {
  ll s = max(a1, a2);
  ll e = min(b1, b2);

  return {s, e};
}


bool isNonEmptyIntersection(ll a1, ll b1, ll a2, ll b2) {
  auto p = getIntersectingRange(a1, b1, a2, b2);
  return p.first <= p.second;
}


double getPointDistance(double x1, double y1, double x2, double y2) {
  double dx = x1-x2;
  double dy = y1-y2;
  double d = (dx * dx) + (dy * dy);
  return sqrt(d);
}


bool isPrime(ll x) {
  if (x == 2 || x == 3 || x == 5 || x == 7) return true;
  if (x < 10) return false;
  ll till = min((ll)sqrt(x) + 1, x-1);
  for (ll i = 2 ; i <= till ; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}


const int TREE_SIZE = 1;


ll segTree[TREE_SIZE], lazyTree[TREE_SIZE];


void updateRange(int node, int start, int end, int l, int r, ll val)
{
    if(lazyTree[node] != 0)
    {
        // This node needs to be updated
        segTree[node] += (end - start + 1) * lazyTree[node];    // Update it
        if(start != end)
        {
            lazyTree[node*2] += lazyTree[node];                  // Mark child as lazyTree
            lazyTree[node*2+1] += lazyTree[node];                // Mark child as lazyTree
        }
        lazyTree[node] = 0;                                  // Reset it
    }
    if(start > end or start > r or end < l)              // Current segment is not within range [l, r]
        return;
    if(start >= l and end <= r)
    {
        // Segment is fully within range
        segTree[node] += (end - start + 1) * val;
        if(start != end)
        {
            // Not leaf node
            lazyTree[node*2] += val;
            lazyTree[node*2+1] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);        // Updating left child
    updateRange(node*2 + 1, mid + 1, end, l, r, val);   // Updating right child
    segTree[node] = segTree[node*2] + segTree[node*2+1];        // Updating root with max value
}


ll queryRange(int node, int start, int end, int l, int r)
{
    if(start > end or start > r or end < l)
        return 0;         // Out of range
    if(lazyTree[node] != 0)
    {
        // This node needs to be updated
        segTree[node] += (end - start + 1) * lazyTree[node];            // Update it
        if(start != end)
        {
            lazyTree[node*2] += lazyTree[node];         // Mark child as lazyTree
            lazyTree[node*2+1] += lazyTree[node];    // Mark child as lazyTree
        }
        lazyTree[node] = 0;                 // Reset it
    }
    if(start >= l and end <= r)             // Current segment is totally within range [l, r]
        return segTree[node];
    int mid = (start + end) / 2;
    ll p1 = queryRange(node*2, start, mid, l, r);         // Query left child
    ll p2 = queryRange(node*2 + 1, mid + 1, end, l, r); // Query right child
    return (p1 + p2);
}






















const int MAXN = 1e5+1;
const int MAXM = 2e5+1;
const ll INF = 1e15+1;


int N, M, S, T;
int ar_u[MAXM], ar_v[MAXM];
ll dist_S[MAXN], dist_T[MAXN], memo_S[MAXN], memo_T[MAXN], ar_d[MAXM];
vector< pair<int, long> > G[MAXN];


void getShortestPath(int src, ll * dist) {
  for (int i = 1 ; i <= N ; i++) {
    dist[i] = INF;
  }
  vector<bool> visit(N+1, false);
  dist[src] = 0;
  set< pair<ll, int> > Q;
  Q.insert({0, src});
  while (!Q.empty()) {
    int at = Q.begin()->second;
    Q.erase(Q.begin());
    if (visit[at]) continue;
    visit[at] = true;
    for (auto p : G[at]) {
      int nxt = p.first;
      ll d = p.second;
      if (dist[at] + d < dist[nxt]) {
        dist[nxt] = dist[at] + d;
        Q.insert({dist[nxt], nxt});
      }
    }
  }
}


void input() {
  cin >> N >> M >> S >> T;
  int u, v;
  ll d;
  for (int i = 1 ; i <= M ; i++) {
    cin >> u >> v >> d;
    G[u].push_back({v, d});
    G[v].push_back({u, d});
    ar_u[i] = u;
    ar_v[i] = v;
    ar_d[i] = d;
  }
}


void preprocess() {
  getShortestPath(S, dist_S);
  getShortestPath(T, dist_T);
}


void solve() {
  vector< pair<ll, int> > v_S, v_T;
  for (int i = 1 ; i <= N ; i++) {
    v_S.push_back({dist_S[i], i});
    v_T.push_back({dist_T[i], i});
  }
  sort(v_S.begin(), v_S.end());
  sort(v_T.begin(), v_T.end());
  memo_S[S] = 1;
  memo_T[T] = 1;
  for (int i = 1 ; i < N ; i++) {
    int at = v_S[i].second;
    //cerr << "At - S = " << at << "\n";
    for (auto p : G[at]) {
      int nxt = p.first;
      ll d = p.second;
      if (dist_S[nxt] + d == dist_S[at]) {
        memo_S[at] = modSum(memo_S[at], memo_S[nxt]);
      }
    }
    at = v_T[i].second;
    //cerr << "At - T = " << at << "\n";
    for (auto p : G[at]) {
      int nxt = p.first;
      ll d = p.second;
      if (dist_T[nxt] + d == dist_T[at]) {
        memo_T[at] = modSum(memo_T[at], memo_T[nxt]);
      }
    }
  }
  ll ans = modProd(memo_S[T], memo_S[T]);
  ll D = dist_S[T];
  //cerr << "D = " << D << "\n";
  //cerr << "Init Ans = " << ans << "\n";
  for (int i = 1 ; i <= N ; i++) {
    if (dist_S[i] == dist_T[i] && dist_S[i] * 2 == D) {
      //cerr << "I = " << i << "\n";
      //cerr << "memo_S = " << memo_S[i] << "\n";
      //cerr << "memo_T = " << memo_T[i] << "\n";
      ans = modSubtract(ans, modProd(memo_S[i], modProd(memo_T[i], modProd(memo_S[i], memo_T[i]))));
    }
  }
  for (int i = 1 ; i <= M ; i++) {
    int u = ar_u[i];
    int v = ar_v[i];
    ll d = ar_d[i];
    if (dist_S[u]*2 < D && dist_T[v]*2 < D && dist_S[u] + dist_T[v] + d == D) {
      ans = modSubtract(ans, modProd(memo_S[u], modProd(memo_T[v], modProd(memo_S[u], memo_T[v]))));
    }
    if (dist_T[u]*2 < D && dist_S[v]*2 < D && dist_T[u] + dist_S[v] + d == D) {
      ans = modSubtract(ans, modProd(memo_T[u], modProd(memo_S[v], modProd(memo_T[u], memo_S[v]))));
    }
  }
  cout << ans;
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cerr.tie(0);

  int T;
//  cin >> T;
  T = 1;

  for (int i = 0 ; i < T ; i++) {
    input();
    preprocess();
    solve();
  }

  return 0;
}

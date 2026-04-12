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
    return modProd(tmp, tmp);
  } else {
    ll tmp = getPowMod(x, e-1, MOD);
    return modProd(tmp, x);
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




















const int MAXN = 200001;


int N;
ll ar[MAXN];


void input() {
  cin >> N;
  for (int i = 1 ; i <= N ; i++) {
    cin >> ar[i];
  }
}


void preprocess() {
}


void solve() {
  deque<ll> Q;
  for (int i = 1 ; i <= N ; i++) {
    if (i % 2 == 1) {
      Q.push_back(ar[i]);
    } else {
      Q.push_front(ar[i]);
    }
  }
  if (N % 2 == 1) {
    reverse(Q.begin(), Q.end());
  }
  for (auto x : Q) {
    cout << x << " ";
  }
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

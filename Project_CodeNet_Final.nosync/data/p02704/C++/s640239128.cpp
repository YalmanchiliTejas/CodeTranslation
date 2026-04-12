/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
//const ll mod = 998244353;


inline void normal(ll &a) { a %= mod; (a < 0) && (a += mod); }
inline ll modMul(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); return (a * b) % mod; }
inline ll modAdd(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); return (a + b) % mod; }
inline ll modSub(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while (p) { if (p & 1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, mod - 2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

#define si(x) scanf("%d",&x)
#define sii(x,y) scanf("%d %d",&x,&y)
#define siii(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define sl(x) scanf("%lld",&x)
#define sll(x,y) scanf("%lld %lld",&x,&y)
#define slll(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define ss(ch) scanf("%s",ch)
#define pi(x) printf("%d",x)
#define pii(x,y) printf("%d %d",x,y)
#define piii(x,y,z) printf("%d %d %d",x,y,z)
#define pl(x) printf("%lld",x)
#define pll(x,y) printf("%lld %lld",x,y)
#define plll(x,y,z) printf("%lld %lld %lld",x,y,z)
#define ps(ch) printf("%s",ch)
#define F(i,a,b)      for(int i= a; i <= b; i++)
#define R(i,b,a)      for(int i= b; i >= a; i--)

/* for Random Number generate
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
*/
///**
template < typename F, typename S >ostream& operator << ( ostream& os, const pair< F, S > & p ) {return os << "(" << p.first << ", " << p.second << ")";}
template < typename T >ostream &operator << ( ostream & os, const vector< T > &v ) {os << "{"; for (auto it = v.begin(); it != v.end(); ++it) {if ( it != v.begin() ) os << ", "; os << *it;} return os << "}";}
template < typename T >ostream &operator << ( ostream & os, const set< T > &v ) {os << "["; for (auto it = v.begin(); it != v.end(); ++it) {if ( it != v.begin()) os << ", "; os << *it;} return os << "]";}
template < typename F, typename S >ostream &operator << ( ostream & os, const map< F, S > &v ) {os << "["; for (auto it = v.begin(); it != v.end(); ++it) {if ( it != v.begin() ) os << ", "; os << it -> first << " = " << it -> second ;} return os << "]";}
#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
clock_t tStart = clock();
#define timeStamp dbg("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)
void faltu () { cerr << endl; }
template <typename T>void faltu( T a[], int n ) {for (int i = 0; i < n; ++i) cerr << a[i] << ' '; cerr << endl;}
template <typename T, typename ... hello>
void faltu( T arg, const hello &... rest) { cerr << arg << ' '; faltu(rest...); }

// Program showing a policy-based data structure.
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less 
using namespace __gnu_pbds;

// GNU link : https://goo.gl/WVDL6g
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        new_data_set;
// find_by_order(k) – ফাংশনটি kth ordered element এর একটা পয়েন্টার রিটার্ন করে। অর্থাৎ তুমি চাইলেই kth ইন্ডেক্সে কি আছে, সেটা জেনে ফেলতে পারছো!
// order_of_key(x) – ফাংশনটি x এলিমেন্টটা কোন পজিশনে আছে সেটা বলে দেয়।
//*//**___________________________________________________**/
const int N = 1000006;

void fail()
{
  cout << -1 << "\n";
  exit(0);
}


int main()
{
  FASTIO
/*
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
#endif
  //*/
  int n;
  cin >> n;
  string a[505], c[505];
  uint64_t B[505], D[505];

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x == 0)a[i] = "and";
    else a[i] = "or";
  }

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x == 0) c[i] = "and";
    else c[i] = "or";
  }

  for (int i = 0; i < n; i++) cin >> B[i];
  for (int i = 0; i < n; i++) cin >> D[i];

  uint64_t ans[505][505] = {{}};

  for (int i = 0; i < 64; i++) {
    vector<vector<int>> decide(n, vector<int>(n, -1));

    vector<pair<int, int>> x, y;

    for (int j = 0; j < n; j++) { //horizontal(col)
      if (a[j] == "and") {
        if ((B[j] >> i) & 1)
          for (int k = 0; k < n; k++)decide[j][k] = 1;
        else x.emplace_back(j, 0);
      }
      else {
        if ((~B[j] >> i) & 1)
          for (int k = 0; k < n; k++)decide[j][k] = 0;
        else x.emplace_back(j, 1);
      }
    }

    for (int j = 0; j < n; j++) {
      if (c[j] == "and") {
        if ((D[j] >> i) & 1) {
          for (int k = 0; k < n; k++)
            if (decide[k][j] == 0)fail();
          for (int k = 0; k < n; k++)decide[k][j] = 1;
        }
        else y.emplace_back(j, 0);
      }
      else {
        if ((~D[j] >> i) & 1) {
          for (int k = 0; k < n; k++)
            if (decide[k][j] == 1)fail();
          for (int k = 0; k < n; k++)decide[k][j] = 0;
        }
        else y.emplace_back(j, 1);
      }
    }

    if (min(x.size(), y.size()) >= 2) {
      for (int j = 0; j < (int)x.size(); j++) {
        for (int k = 0; k < (int)y.size(); k++) {
          decide[x[j].first][y[k].first] = (j + k) & 1;
        }
      }
    }

    else if ((int)x.size() == 1) {
      for (auto &p : y) {
        bool ex = false;
        for (int j = 0; j < n; j++) ex |= (decide[j][p.first] == p.second);
        decide[x[0].first][p.first] = ex ? x[0].second : p.second;
      }
      bool f = false;
      for (int k = 0; k < n; k++) f |= decide[x[0].first][k] == x[0].second;
      if (!f)fail();
    }

    else if ((int)y.size() == 1) {
      for (auto &p : x) {
        bool ex = false;
        for (int j = 0; j < n; j++) ex |= (decide[p.first][j] == p.second);
        decide[p.first][y[0].first] = ex ? y[0].second : p.second;
      }
      bool f = false;
      for (int k = 0; k < n; k++) f |= decide[k][y[0].first] == y[0].second;
      if (!f)fail();
    }

    else {
      for (auto &p : x) {
        bool f = false;
        for (int k = 0; k < n; k++) f |= decide[p.first][k] == p.second;
        if (!f)fail();
      }

      for (auto &p : y) {
        bool f = false;
        for (int k = 0; k < n; k++) f |= decide[k][p.first] == p.second;
        if (!f)fail();
      }
    }

    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++)
        ans[j][k] |= ((uint64_t)decide[j][k] & 1) << i;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }

}
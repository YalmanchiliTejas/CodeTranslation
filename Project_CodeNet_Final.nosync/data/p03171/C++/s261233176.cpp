#include <bits/stdc++.h>

#define mp make_pair
#define fst first
#define snd second
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forn1(i,n) for (int i = 1; i <= int(n); i++)
#define popcnt __builtin_popcount

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

template <typename T> T id(T b) {return b;};
template <class It> bool all(It f,It l){return std::all_of(f,l,id<bool>);}
template <class It> bool any(It f,It l){return std::any_of(f,l,id<bool>);}
template <typename T> void chmax(T &x, T y) {if (x < y) x = y;}
template <typename T> void chmin(T &x, T y) {if (x > y) x = y;}

const int MAX_N = 3000;
int n;
ll a[MAX_N];
ll dp[MAX_N][MAX_N][2];
bool vis[MAX_N][MAX_N][2];

ll rec(int l, int r, int p) {
  if (vis[l][r][p]) return dp[l][r][p];

  vis[l][r][p] = true;

  if (l == r) {
    return dp[l][r][p] = a[l];
  } else {
    ll v1 = a[l] - rec(l+1,r,1-p);
    ll v2 = a[r] - rec(l,r-1,1-p);

    return dp[l][r][p] = max(v1,v2);
  }
}

int main()
{
#ifdef FASTIO
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
#endif

  cin >> n;
  forn(i,n) cin >> a[i];

  cout << rec(0,n-1,0) << endl;

  return 0;
}

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

const int MAX_N = 100000;
int n;
ll s[MAX_N];

int main()
{
#ifdef FASTIO
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
#endif

  cin >> n;
  forn(i,n) cin >> s[i];

  ll res = 0;
  for (int c = 1; c < n; c++) {
    ll score = 0;
    for (int i = 0; i*c < n-1; i++) {
      if (i*c == (n-1)-i*c || (i-1)*c == (n-1)-i*c || i*c == (n-1)*(i-1)*c)
        break;
      int a = (n-1)-i*c;
      if (a <= 0 || a-c <= 0) continue;
      score += s[i*c];
      score += s[(n-1)-i*c];
      chmax(res,score);
    }
  }

  cout << res << endl;

  return 0;
}

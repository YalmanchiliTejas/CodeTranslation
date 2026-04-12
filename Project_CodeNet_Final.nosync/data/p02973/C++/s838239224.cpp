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
void fastio() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }

const int MAX_N = 100000;
int n;
int a[MAX_N];

int main()
{
  cin >> n;
  forn(i,n) cin >> a[i];

  int c = 0;
  multiset<int> s;
  forn(i,n) {
    if (s.empty() || *s.begin() >= a[i]) {
      c++;
    } else {
      auto it = s.lower_bound(a[i]);
      it--;
      s.erase(it);
    }
    s.insert(a[i]);
  }

  cout << c << endl;

  return 0;
}

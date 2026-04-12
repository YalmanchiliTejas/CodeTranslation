#include <bits/stdc++.h>
/* Karen {{{
  ___  ____
 |_  ||_  _|
   | |_/ /    ,--.   _ .--.  .---.  _ .--.
   |  __'.   `'_\ : [ `/'`\]/ /__\\[ `.-. |
  _| |  \ \_ // | |, | |    | \__., | | | |
 |____||____|\'-;__/[___]    '.__.'[___||__]
}}} */
/* cpp template {{{*/
using namespace std;

#define endl '\n'

#define REP(i, n) for (int i = 0; i < (n); i++)
#define REPS(i, a, n) for (int i = (a); i < (n); i++)
#define RREP(i, n) for (int i = 1; i <= (n); i++)
#define EQ(n,m) (abs((n)-(m)) < EPS)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()

typedef double D;
typedef long long ll;
typedef long double lb;
typedef complex<D> P;
typedef vector<P> VP;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;

inline bool inside(int y,int x,int H,int W){return(y>=0&&x>=0&&y<H&&x<W);}
inline int in() {int x; std::cin >> x; return x;}

template <typename T>
void print(std::vector<T>& v, char c = ' ') {
  REP(i, v.size()) {
    if (i != 0) std::cout << c;
    std::cout << v[i];
  }
  std::cout << endl;
}
template <typename T>
void print(T x) {
  std::cout << x << '\n';
}
/* }}} */
/* 定数 {{{*/
const ll MOD = 1e9 + 7;
const ll INF = 1e9 + 9;
const D EPS  = 1e-9;
const int dx[] = {0, 1, 0, -1, 1, -1, 1, -1};
const int dy[] = {1, 0, -1, 0, 1, -1, -1, 1};
/* }}} */

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int h = in(), w = in();

  int cnt = 0;
  REP(i, h) REP(j, w){
    char a;
    cin >> a;
    if (a == '#') cnt++;
  }

  cout << (cnt == w + h - 1 ? "Possible" : "Impossible") << endl;

}


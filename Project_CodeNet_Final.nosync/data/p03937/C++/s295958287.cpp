#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define blank(ans) cout << (ans) << " ";
#define mp(p, q) make_pair(p, q)
#define mt(p, q, r) make_tuple(p, q, r)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef string str;

typedef vector<ll> vll;
typedef vector<ld> vd;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<str> vs;
typedef vector<vector<ll>> vvll;
typedef vector<vector<ld>> vvd;
typedef vector<vector<char>> vvc;
typedef vector<vector<str>> vvs;
typedef vector<pair<ll, ll>> vpll;
typedef vector<tuple<ll, ll, ll>> vtlll;

const ld PI = acos(-1.0);
const ll MAX = 9000000000000000000;
const ll MIN = -9000000000000000000;
const ld DMAX = 4500;
const ld DMIN = -4500;
const ll MOD = 1000000007;

template <typename T>
void fin(T a)
{
  cout << a << endl;
  exit(0);
}

//実行部
void Main()
{
  ll h, w; cin >> h >> w;
  ll flag = 0;
  vvc a(h, vc(w)); rep(i, h) rep(j, w) { cin >> a[i][j]; if(a[i][j] == '#') flag++;}
  ll right = 0, down = 0;
  if(a[0][0] != '#') fin("Impossible");
  while(1)
  {
    if(right < h - 1&&a[right + 1][down] == '#')
    {
      right++;
      flag--;
    }
    else if(down < w - 1&&a[right][down + 1] == '#')
    {
      down++;
      flag--;
    }
    else
    {
      break;
    }
  }
  if(flag == 1) fin("Possible");
  else fin("Impossible");
}

//前処理
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(20); //高精度少数表示
  Main();
  return 0;
}

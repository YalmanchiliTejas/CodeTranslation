#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rrep(i, n) for (ll i = (n - 1); i >= 0; --i)
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
typedef vector<vector<bool>> vvb;
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

typedef vector<map<char, ll>> vmcl;

void Main()
{
  ll n; cin >> n;
  vs s(n); rep(i, n) cin >> s[i];
  vmcl ans(n);
  rep(i, n)
  {
    rep(j, s[i].size())
    {
      if(ans[i].count(s[i][j])) ans[i][s[i][j]]++;
      else ans[i][s[i][j]] = 1;
    }
  }
  /*
  rep(j, n)
  {
    for(char i = 'a';i <= 'z';i++)
    {
      cout << ans[j][i] << " ";
    }
    cout << endl;
  }
  */
  for(char i = 'a';i <= 'z';i++)
  {
    ll A = MAX;
    rep(j, n)
    {
      A = min(A, ans[j][i]);
    }
    rep(k, A)
    {
      cout << i;
    }
  }
  fin("");
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

/*
//test時
  g++ test.cpp -o test;./test
*/

#include<bits/stdc++.h>

using namespace std;

typedef long long int llint;
typedef pair<int, int> pii;
typedef pair<llint, llint> pll;
typedef vector<int> vi;
typedef vector<llint> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define ci cin
#define co cout
#define en endl
#define ln cout<< '\n'
#define rep(i, n) for(int i = 0; i < n; i++)
#define outl(x) cout<< (x) << '\n'
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007

template<typename Tn> Tn gcd(Tn a, Tn b)
{
  return (b ? gcd(b, a % b) : a);
}

template<typename Tn> Tn lcm(Tn a, Tn b)
{
  return a / gcd(a, b) * b;
}

llint cnt = 0;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

vector<string> v, v2, v3, v4, v5;

int main()
{
  int h, w;
  ci >> h >> w;

  string s;
  rep(i, h) ci >> s, v.pb(s);

  string all = "";
  rep(i, w) all += '.';

  rep(i, h) if(v[i] != all) v2.pb(v[i]);

  rep(i, w) {
    string hoge = "";
    rep(j, v2.size()) hoge += v2[j][i];
    
    v3.pb(hoge);
  }

  all = "";
  rep(i, v3[0].size()) all += '.';
  rep(i, v3.size()) if(v3[i] != all) v4.pb(v3[i]);

  rep(i, v4[0].size()) {
    string hoge = "";
    rep(j, v4.size()) hoge += v4[j][i];
    
    v5.pb(hoge);
  }
  
  rep(i, v5.size()) co << v5[i] << en;
  
  return 0;
}

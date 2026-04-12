#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <set>
#include <cstdio>
#include <vector>
#include <iostream>
#include <utility>
#include <queue>
#include <map>

#define fir first
#define sec second
#define sz(s) (s).size()
#define pb push_back
#define get(n) scanf("%d",&n);
#define gets(s) string s;cin >> (s);
#define prfi(n) printf("%d", &n);
#define prfd(n) printf("%lf", &n);
#define All(s) (s).begin(), (s).end()
#define rep(i,j) for(int (i)=0;(i)<(j);(i)++)
#define For(i,j,k) for(int (i)=(j);(i)<(k);(i)++)
#define drep(i,j) for(int (i)=(j);(i)>=0;(i)--)
#define Ford(i,j,k) for(int (i)=(j);i>=(k);i--)
#define vfor(c,v) for(auto (c): (v))
#define lpi(n) for(int i=0;i<(n);i++)
#define lpj(n) for(int j=0;j<(n);j++)
#define lpz(n) for(int z=0;z<(n);z++)
#define mem(a,b) memset(a,b,sizeof(a));
#define dump(x)  std::cout << #x << " = " << (x) << std::endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
using ll = long long;
using ld = long double;
using pii = std::pair<int,int>;
using pll = std::pair<ll, ll>;
using vi = std::vector<int> ;
using vvi = std::vector<vi> ;
using vll = std::vector<ll>;
using vvll = std::vector<vll>;
using vd = std::vector<double> ;
using vvd = std::vector<vd> ;
using qi = std::queue<int> ;
using vpii = std::vector<std::pair<int, int> >;
using vpll = std::vector<pll>;
using namespace std;

const int Mod = (1e9) + 7;
const int INF = 1e9 + 19;
const ll INFL = 1e18 + 19;
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};
const int dx2[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
const int dy2[] = {1, 0, -1, 1, 0, -1, 1, 0, -1};
//_____________________________________Templates_________________________________________//

template<class T1, class T2> inline void chmin(T1 &a, T2 b){if(a > b) a = b;}
template<class T1, class T2> inline void chmax(T1 &a, T2 b){if(a < b) a = b;}
template<class T> inline void pri(T a){cout << a << endl;}
template<class Z> using vec = vector<Z>;
//mainly use for dynamic prog
template<class T1, class T2>
void update(T1 &a, T2 b){
  a += b;
  if(a > Mod) a %= Mod;
}

inline void IN(void){
  return;
}

template <typename First, typename... Rest>
void IN(First& first, Rest&... rest){
  cin >> first;
  IN(rest...);
  return;
}

inline void OUT(void){
  cout << "\n";
  return;
}

template <typename First, typename... Rest>
void OUT(First first, Rest... rest){
  cout << first << " ";
  OUT(rest...);
  return;
}

bool pairsort(pll pl, pll pr){
  if(pl.first == pr.first)return pl.second > pr.second;
  return pl.first < pr.first;
}

int cntbit(ll a,int n,int j){int res = 0;For(i,j,n){if(a>>i & 1){res++;}}return res;}
vector<int> make_bit(int a){vector<int> res; lpi(32)if(a&(1<<i))res.pb(i);return res;}
bool stdbit(int a, int b){return a&(1 << b); }
int GCD(int a, int b){if(b > a)return GCD(b,a);if(a%b == 0)return b;else return GCD(b, a%b);}
int LCM(int a, int b){return a*b/GCD(a,b);}
int roundup(int a, int b){if(a % b == 0)return a/b;else return (a+b)/b;}
int rounddown(int a, int b){if(a%b == 0)return a/b;else {return (a-b)/b;}}
ll GetDiviserCount(ll N)//約数の個数
{
  ll res = 1;
  For(i,2,sqrt(N)+1)
  {
    ll cnt = 0;
    while(N%i == 0)
    {
      cnt++;
      N /= i;
    }
    res *= (cnt + 1);
    if(N == 1)break;
  }
  if(N != 1)res *= 2;
  return res;
}
vll GetDivisor(ll N)//約数列挙
{
  vll res;
  for(ll i = 1;i*i <= N;i++)
  {
    if(N%i == 0)
    {
      res.pb(i);
      if(i*i != N)res.pb(N/i);
    }
  }
  sort(All(res));
  return res;
}

struct BIT{
  using T = ll;
  vector<T> data;
  T UNIT;
  int n;

  BIT(int n,T a) : n(n), UNIT(a){
    data.resize(n+1,UNIT);
  }

  T sum (int i){
    int s = 0;
    while(i > 0){
      s += data[i];
      i -= i & -i;
    }
    return s;
  }

  void add(int i, T x){
    while(i <= n){
      data[i] += x;
      i += i & -i;
    }
  }
  T range(int r, int l){
    return sum(r) - sum(l-1);
  }

  int lower_bound(T w){
    if(w <= 0)return 0;
    int x = 0;
    int pos = 1, N = n+1;
    while(pos * 2 <= N){
      pos *= 2;
    }
    for(int k = pos;k>0;k /= 2){
      if(x + k <= N && data[x + k] <= w){
        w -= data[x + k];
        x += k;
      }
    }
    return x + 1;
  }
};



//_____________________　following sorce code_________________________//
const int max_n = 3 * (1e5) + 1;
const int max_m = 83 * (1e5) + 1;

int n,m,k;
ll N;
int h,w;
vvi tree;
string S;
int a,b,c;
vi v;
int ans;

int main () {
  cin.tie(0);
  ios::sync_with_stdio(false);
  IN(n);
  vll moun;
  vll a(n);
  rep(i,n)IN(a[i]);
  ans = 1;
  moun.pb(a[0]);
  For(i,1,n)
  {
    //sort(All(moun));
    if(a[i] <= moun[sz(moun)-1])
    {
      ans++;
      moun.pb(a[i]);
    }
    else 
    {
      int l = -1, r = sz(moun)-1;
      while(l+1<r)
      {
        int c = (l+r)/2;
        if(moun[c] < a[i])r = c;
        else l = c;
      }
      moun[r] = a[i];
    }
    /*
    OUT("moun");
    for(auto c : moun)cout << c << " ";
    OUT();
    */
  }

  cout << ans << endl;
  //for(auto c : ans){cout << c << endl;}
  //cout << fixed << setprecision(15) << ans << endl;
  return 0;
}
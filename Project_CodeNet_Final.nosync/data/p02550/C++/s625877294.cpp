//FIRST THINK THEN CODE.

#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

#define rep(i,a,b) for(ll i=a;i<b;++i)
#define rrep(i,a,b) for(ll i=a;i>b;--i)
#define FOR(i,n)  for(ll i=0;i<n;i++)
#define vi vector<int>
#define vl vector<ll>
#define ld long double
#define vld vector<ld>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define vvld vector<vector<ld>>
#define pii pair<int,int>
#define pll pair<long,long>
#define vpii vector<pii>
#define vpll vector<pll>
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define d1(x) cout<<(x)<<endl
#define d2(x,y) cout<<(x)<<" "<<(y)<<endl
#define d3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl
#define d4(a,b,c,d) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<endl
#define PI 3.1415926535897932384626433832795
#define fix(f,n) fixed<<setprecision(n)<<f
#define all(x) x.begin(),x.end()
#define rev(p) reverse(p.begin(),p.end());
#define endl "\n"
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define popcount(x) __builtin_popcountll(x)
#define sz(x) ((ll)x.size())
const ll M = 1000000007;
const ll MM = 998244353;
ll begtime = clock();
#define end_routine() cout << "\n\nTime elapsed: " << (clock() - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n";
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//#define trace(...)
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

template<typename T, typename F>
void chmax( T &a, F b) {
  if (b > a)a = b;
}

template<typename T, typename F>
void chmin( T &a, F b) {
  if (b < a)a = b;
}



/* if you want to multiply 2 64 bit numbers mod c.
 i.e a*b%c.
 this function will help  in preventing "overflow".
*/

ll mulmod(ll a, ll b, ll c) {

  ll ans = 0;
  ll y = a % c;
  while (b) {
    if (b & 1) {
      (ans += y) %= c;
    }
    y = y * 2 % c;
    b >>= 1;
  }
  return ans;

}



ll powM(ll a, ll b, ll m)
{
  if (a <= 0)return 0;
  a %= m;

  ll ans = 1LL;
  while (b)
  {
    if (b & 1)ans = ans * a % m;
    //ans = mulmod(ans, a, m);
    a = a * a % m;
    //a = mulmod(a, a, m);
    b >>= 1;
  }

  return ans;
}

ll powMbig(ll a, ll b, ll m)
{
  if (a <= 0)return 0;
  a %= m;

  ll ans = 1LL;
  while (b)
  {
    if (b & 1)//ans = ans * a % m;
      ans = mulmod(ans, a, m);
    //a = a * a % m;
    a = mulmod(a, a, m);
    b >>= 1;
  }

  return ans;
}




ll poww(ll a, ll b)
{

  ll ans = 1;
  while (b)
  {
    if (b & 1)ans = ans * a;
    a = a * a;
    b >>= 1;
  }

  return ans;

}


string tostring(ll x) {
  stringstream sss;
  sss << x;
  string ans = sss.str();
  return ans;
}



const ll N = 1e6 + 5;



int main() {

  IOS;

#ifndef ONLINE_JUDGE

  freopen("input1.txt", "r", stdin);
  freopen("output1.txt", "w", stdout);

#endif

  ll n, x, m;
  cin >> n >> x >> m;

  ll safe = x;

  ll cyc = 0;

  if (n <= m) {
    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
      ans = (ans + x) ;
      x = x * x % m;
      //  d2("hi", x);
    }
    cout << ans << endl;
    return 0;
  }

  ll start = 0;

  vl f(m);

  ll ans1 = 0;


  for (ll i = 1; i <= m + 1; i++) {
    //d2(i, x);
    if (f[x] > 0) {
      cyc = i - f[x];
      start = f[x];
      ans1 += x;
      //d2("hi", 1);
      break;
    }
    f[x] = i;
    ans1 += x;
    // d2("hi", x);
    // blah[i] = ans1;
    x = x * x % m;
  }
// d2(start, cyc);
  //d1(ans1);
// cycle wala part ka calculate karke rakh le.

  x = safe;

  for (ll i = 0; i < start ; i++) {
    x = x * x % m;
  }

  ll ans2 = 0;

  vl dp(cyc + 1);

  for (ll i = start; i < start + cyc; i++) {
    ans2 = (ans2 + x) ;
    dp[i - start + 1] = ans2;
    x = x * x % m;
  }

  ans1 -= ans2;

  //d1(rem);

  ll q = (n - start ) / cyc;

  ll rem = (n - start ) % cyc;


  //d2(q, rem);

  ll ans3 = q * ans2;

  ll ans4 = dp[rem];

  ll fin = (ans4 + ans3 + ans1) ;

  cout << fin;


  return 0;
}
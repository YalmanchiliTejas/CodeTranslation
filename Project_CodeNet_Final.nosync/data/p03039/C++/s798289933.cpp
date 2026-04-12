#include <bits/stdc++.h>
using namespace std;

//repetition
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

//container util
#define all(x) (x).begin(),(x).end()

//typedef
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

//const value
//const ll MOD = 1e9 + 7;
//const int dx[] = {0,1,0,-1};//{0,0,1,1,1,-1,-1,-1};
//const int dy[] = {1,0,-1,0};//{1,-1,0,1,-1,0,1,-1};

//conversion
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
inline ll toLL(string s) {ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

#define MOD (long)(1e9 + 7)

long long modPow(int x, int n){
  if(n == 0) return 1;
  if(n % 2 == 0) {
    long long sqrtX = modPow(x,n/2);
    return sqrtX * sqrtX % MOD ;
  }else{
    return x * modPow(x,n-1) % MOD;
  }
}

long long kaizyou(long long x){
  long long res = 1;
  for(int i = 1; i <= x; i++){
    res = (res * i) % MOD;
  }
  return res;
}

long long modCombi(long long a, long long b){
  if(b > a/2) return modCombi(a,a-b);
  return ((kaizyou(a) * modPow(kaizyou(b),MOD - 2)) % MOD)* modPow(kaizyou(a-b),MOD - 2) % MOD;
}

ll calc(ll n, ll m){
  ll res = 0;
  rep(i,n){
    res += i * (n-i) * m * m;
    res %= MOD;
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,m,k;
  cin >> n >> m >> k;
  ll com = modCombi(n*m-2, k-2);
  ll ans = com * calc(n,m);
  ans %= MOD;
  ans += calc(m,n) * com ;
  ans %= MOD;
  cout << ans << endl;
  return 0;
}

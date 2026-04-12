#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
const ll INF = 1e+14;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second

void Yes(){
	cout<<"Yes"<<endl;
	exit(0);
}
 
void No(){
	cout<<"No"<<endl;
	exit(0);
}
 int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

ll extgcd(ll a, ll b, ll& x, ll& y) {
    ll d = a;
    if(b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1; y = 0;
    }
    return d; 
}

ll mod_inverse(ll a, ll m) {
    ll x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N, M, K; cin >> N >> M >> K;
  ll A = 0, B = 0;
  for(ll i = 1LL; i <= N - 1; i++) {
      A += i * (N - i);
      A %= mod;
  }
  A *= M;
  A %= mod;
  A *= M;
  A %= mod;
  for(ll i = 1LL; i <= M - 1; i++) {
      B += i * (M - i);
      B %= mod;
  }
  B *= N;
  B %= mod;
  B *= N;
  B %= mod;
  ll C = 1;
  for(ll i = 0 ; i < K - 2; i++) {
      C *= (N * M - 2 - i);
      C %= mod;
  }
  for(ll i = 1 ; i <= K - 2; i++) {
      C *= mod_inverse(i, mod);
      C %= mod;
  }
  ll ans = A + B;
  ans %= mod;
  ans *= C;
  ans %= mod;
  cout << ans << endl;
  return 0;
}
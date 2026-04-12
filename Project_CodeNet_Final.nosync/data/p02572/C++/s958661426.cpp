#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef pair<int,int> pii;
typedef pair<long long, int> pli;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) (x).size()

ll mod = 1000000007;

ll gcd(ll a, ll b){
  if (a%b == 0)return(b);
  else return(gcd(b, a%b));
}

ll inv(ll x){
  ll res = 1;
  ll k = mod - 2;
  ll y = x;
  while(k){
    if(k&1)res = (res*y)%mod;
    y = (y*y) % mod;
    k /= 2;
  }
  return res;
}

struct Square {
  int h,w,cnt;
  Square(int _h,int _w,int _cnt){
    h = _h;
    w = _w;
    cnt = _cnt;
  }
};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vll a(n);
  rep(i,n)cin >> a[i];
  ll sum = 0;
  rep(i,n){
    sum += a[i];
    sum %= mod;
  }

  ll ret = 0;
  rep(i,n){
    ll b = sum - a[i];
    if(b < 0)b += mod;
    ret = (ret + a[i] * b % mod) % mod;
  }

  ret = ret * inv(2) % mod;

  cout << ret << endl;
}
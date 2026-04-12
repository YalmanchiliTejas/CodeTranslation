//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (int)(n);i++)
using ll = long long;
const ll MOD=1000000007;
//const ll MOD=998244353;
const long long INF = 1LL << 60;
const double pi=acos(-1.0);

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

//https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a

ll mod_pow(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * x % MOD;  // n の最下位bitが 1 ならば x^(2^i) をかける
        x = x * x % MOD;
        n >>= 1;  // n を1bit 左にずらす
    }
    return ret;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // cout << fixed << setprecision(15);

  ll N; cin>>N;
  vector<ll> A(N); rep(i,N) cin>>A[i];
  ll sum=0; rep(i,N) sum=(sum+A[i])%MOD;
  ll sum2=0; rep(i,N) sum2=(sum2+A[i]*A[i])%MOD;
  ll ans=(sum*sum-sum2)%MOD; if(ans<0) ans+=MOD;
  ans*=mod_pow(2,MOD-2); ans%=MOD;
  
  cout<<ans<<endl;
  
  return 0;
}
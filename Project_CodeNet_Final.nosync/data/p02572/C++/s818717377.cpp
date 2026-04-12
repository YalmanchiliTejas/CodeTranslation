#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_range(i, s, e) for (int i = (s); i < (int)(e); i++)
#define rep_rev(i, s, e) for (int i = (s)-1; i >= (int)(e); i--)
#define sort_vec(v) sort((v).begin(),(v).end())
typedef int64_t lint;
// lint mod = 998244353;
lint mod = 1000000007;
// const int INF=2e9;
template< typename T1, typename T2 >
inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template< typename T1, typename T2 >
inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

int app() {
  int n;
  cin>>n;

  lint asum=0;
  lint a2sum=0;
  rep(i,n){
    lint a;
    cin>>a;
    asum+=a; asum%=mod;
    a2sum+=a*a; a2sum%=mod;
  }

  lint ans=(asum*asum-a2sum+mod)%mod;
  ans*=(mod+1)/2;
  ans%=mod;

  return ans;
}

int main(){cout<<app()<<endl;return 0;}

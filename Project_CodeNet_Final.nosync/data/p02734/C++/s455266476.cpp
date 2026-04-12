#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#ifdef ENABLE_DEBUG
#define dump(a) cerr<<#a<<"="<<a<<endl
#define dumparr(a,n) cerr<<#a<<"["<<n<<"]="<<a[n]<<endl
#else
#define dump(a) 
#define dumparr(a,n) 
#endif
#define FOR(i, a, b) for(ll i = (ll)a;i < (ll)b;i++)
#define For(i, a) FOR(i, 0, a)
#define REV(i, a, b) for(ll i = (ll)b-1LL;i >= (ll)a;i--)
#define Rev(i, a) REV(i, 0, a)
#define REP(a) For(i, a)
#define SIGN(a) (a==0?0:(a>0?1:-1))

typedef long long int ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef pair<ll,pll> ppll;
typedef vector<ll> vll;
typedef long double ld;
typedef pair<ld,ld> pdd;

const ll INF=(1LL<<50);
#if __cplusplus<201700L
ll gcd(ll a, ll b) {
  if(a < b) return gcd(b, a);
  ll r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}
#endif
template<class T>
bool chmax(T& a,const T& b){
  if(a<b){
    a=b;
    return true;
  }
  return false;
}
template<class T>
bool chmin(T& a,const T& b){
  if(a>b){
    a=b;
    return true;
  }
  return false;
}
template<class S,class T>
std::ostream& operator<<(std::ostream& os,pair<S,T> a){
  os << "(" << a.first << "," << a.second << ")";
  return os;
}
template<class T>
std::ostream& operator<<(std::ostream& os,vector<T> a){
  os << "[ ";
  REP(a.size()){
    os<< a[i] << " ";
  }
  os<< " ]";
  return os;
}

const long long MOD = 998244353;
void solve(long long N, long long S, std::vector<long long> A){
  ll ans=0;
  vector<vector<ll>> dp(2,vector<ll>(S+1));
  REP(N){
    ll prev=(i%2)^1;
    ll now=i%2;
    For(j,S+1){
      dp[now][j]=dp[prev][j];
    }
    For(j,S+1-A[i]){
      if(dp[prev][j]>0){
        dp[now][j+A[i]]+=(dp[prev][j])%MOD;
        dp[now][j+A[i]]%=MOD;
      }
    }
    if(A[i]<S+1){
      dp[now][A[i]]+=i+1;
      dp[now][A[i]]%=MOD;
    }
    ans+=dp[now][S];
    ans%=MOD;
  }
  cout<<ans<<endl;
}

int main(){
  cout<<setprecision(1000);
    long long N;
    scanf("%lld",&N);
    long long S;
    scanf("%lld",&S);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, S, std::move(A));
    return 0;
}

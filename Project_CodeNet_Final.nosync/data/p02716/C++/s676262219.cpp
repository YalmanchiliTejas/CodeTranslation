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

ll dp[200001][3];
void solve(long long N, std::vector<long long> A){
  ll ans=0;
  if(N%2==0){
    dp[0][1]=A[0];
    dp[1][0]=A[1];
    dp[2][1]=A[0]+A[2];
    FOR(i,3,N){
      dp[i][1]=dp[i-2][1]+A[i];
      dp[i][0]=max(dp[i-2][0],dp[i-3][1])+A[i];
    }
    ans=max(dp[N-1][0],dp[N-2][1]);
  }else{
    dp[0][2]=A[0];
    dp[1][1]=A[1];
    dp[2][0]=A[2];
    dp[2][2]=A[2]+A[0];
    dp[3][1]=max(A[0],A[1])+A[3];
    FOR(i,4,N){
      dp[i][2]=dp[i-2][2]+A[i];
      dp[i][1]=max(dp[i-2][1],dp[i-3][2])+A[i];
      dp[i][0]=max(dp[i-4][2],max(dp[i-3][1],dp[i-2][0]))+A[i];
    }
    ans=max(dp[N-3][2],max(dp[N-2][1],dp[N-1][0]));

  }
  cout<<ans<<endl;
}

int main(){
  cout<<setprecision(1000);
    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, std::move(A));
    return 0;
}

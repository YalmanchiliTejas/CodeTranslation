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

pll operator+(pll a,pll b){
  return pll(a.first+b.first,a.second+b.second);
}
pll operator-(pll a,pll b){
  return pll(a.first-b.first,a.second-b.second);
}
pll operator*(ll a,pll b){
  return pll(b.first*a,b.second*a);
}
const ll INF=(2000000);
#if __cplusplus<201700L
ll gcd(ll a, ll b) {
  a=abs(a);
  b=abs(b);
  if(a==0)return b;
  if(b==0)return a;
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

template<typename T>
void cnt(T x,map<T,ll> y){
  if(y.count(x)){
    ++y[x];
  }else{
    y[x]=1;
  }
}
void solve(long long N, std::vector<long long> A){
  vector<vector<ll>> dp(N+1,vector<ll>(N+1,-INF));
  ll maxv=0;
  vector<ll> maxvv(N+1,-INF);
  dp[A[0]][A[1]]=dp[A[1]][A[0]]=0;
  maxvv[A[0]]=0;
  maxvv[A[1]]=0;
  ll cnt=0;
  REP(N-1){
    vector<pair<pll,ll>> update;
    auto updf=[&update](pll x,ll y){
      update.push_back(make_pair(x,y));
    };
    map<ll,ll> m;
    vector<ll> mv;
    For(j,3){
      ll tmp=A[3*i+2+j];
      mv.push_back(tmp);
      if(m.count(tmp)){
        ++m[tmp];
      }else{
        m[tmp]=1;
      }
    }
    bool db=false;
    bool end=false;
    ll dbl=0,dbr=0;
    for (auto &&j : m)
    {
      if(j.second==3){
        ++cnt;
        end=true;
      }else if(j.second==2){
        db=true;
        dbl=j.first;
      }else{
        dbr=j.first;
      }
    }
    if(end)continue;
    if(db){
      FOR(k,1,N+1){
        updf(pll(k,dbr),dp[k][dbl]+1);
        updf(pll(dbr,k),dp[k][dbl]+1);
      }
    }
    updf(pll(mv[0],mv[1]),dp[mv[2]][mv[2]]+1);
    updf(pll(mv[0],mv[1]),maxv);

    updf(pll(mv[1],mv[2]),dp[mv[0]][mv[0]]+1);
    updf(pll(mv[1],mv[2]),maxv);

    updf(pll(mv[0],mv[2]),dp[mv[1]][mv[1]]+1);
    updf(pll(mv[0],mv[2]),maxv);

    FOR(j,1,N+1){
      For(k,3){
        updf(pll(mv[k],j),maxvv[j]);
      }
    }
    for (auto &&j : update)
    {
      auto x=j.first.first,y=j.first.second;
      dp[y][x]=dp[x][y]=max(j.second,dp[x][y]);
      maxv=max(maxv,dp[x][y]);
      maxvv[x]=max(maxvv[x],dp[x][y]);
      maxvv[y]=max(maxvv[y],dp[x][y]);
    }
    
  }
  ll ans=0;
  For(i,N+1){
    For(j,N+1){
      if(A.back()==i&&i==j){
        ans=max(ans,dp[i][j]+1);
      }else{
        ans=max(ans,dp[i][j]);
      }
    }
  }
  cout<<ans+cnt<<endl;
}

int main(){
  cout<<setprecision(1000);
    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(3*N);
    for(int i = 0 ; i < 3*N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, std::move(A));
    return 0;
}

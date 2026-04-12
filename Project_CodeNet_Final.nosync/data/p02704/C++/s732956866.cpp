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
ull nbit(ull X,ull i){
  return (X&(1ULL<<i))>0ULL;
}
void solve(long long N, std::vector<long long> S, std::vector<long long> T, std::vector<ull> U, std::vector<ull> V){
  vector<vector<ull>> ans(N,vector<ull>(N));
  For(xx,64){
    ull x=(1ULL<<xx);
    vector<vector<int>> cur(N,vector<int>(N,-1));
    set<ull> flagu,flagv;
    REP(N){
      flagu.insert(i);flagv.insert(i);
    }
    For(i,N){
    ull u=nbit(U[i],xx);
      For(j,N){
        ull v=nbit(V[j],xx);
        if(S[i]!=u&&T[j]!=v&&S[i]!=T[j]){
          cout<<-1<<endl;
          return ;
        }
        if(S[i]!=u){
          cur[i][j]=u;
          flagu.erase(i);
        }
        if(T[j]!=v){
          cur[i][j]=v;
          flagv.erase(j);
        }
        if(u==v){
          cur[i][j]=u;
          flagu.erase(i);
          flagv.erase(j);
        }
      }
    }
    For(__xx,2){
      {
        vector<ll> s;
        for (auto &&i : flagu)
        {
          ull u=nbit(U[i],xx);
          For(j,N){
            if(flagv.count(j))continue;
            if(cur[i][j]==-1){
              cur[i][j]=u;
              s.push_back(i);
            }
          }
        }
        for (auto &&i : s)
        {
          flagu.erase(i);
        }
        
      }
      {
        vector<ll> s;
        for (auto &&j : flagv)
        {
          ull v=nbit(V[j],xx);
          For(i,N){
            if(flagu.count(i))continue;
            if(cur[i][j]==-1){
              cur[i][j]=v;
              s.push_back(j);
            }
          }
        }
        for (auto &&j : s)
        {
          flagv.erase(j);
        }
        
      }

    }
    if(flagu.size()==1||flagv.size()==1||(flagu.empty()^flagv.empty())){
      cout<<-1<<endl;
      return;
    }
    vector<ll> us(flagu.begin(),flagu.end()),vs(flagv.begin(),flagv.end());
    For(i,us.size()){
      For(j,vs.size()){
        if(i%(min(vs.size(),us.size()))==j%(min(vs.size(),us.size()))){
          cur[us[i]][vs[j]]=1;
        }else{
          cur[us[i]][vs[j]]=0;
        }
      }
    }
    For(i,N){
      For(j,N){
        if(cur[i][j]==1){
          ans[i][j]|=x;
        }
      }
    }
  }
  For(i,N){
    For(j,N){
      cout<<ans[i][j]<<" ";
    }
    cout<<endl;
  }
}

int main(){
  cout<<setprecision(1000);
    long long N;
    scanf("%lld",&N);
    std::vector<long long> S(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&S[i]);
    }
    std::vector<long long> T(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&T[i]);
    }
    std::vector<ull> U(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%llu",&U[i]);
    }
    std::vector<ull> V(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%llu",&V[i]);
    }
    solve(N, std::move(S), std::move(T), std::move(U), std::move(V));
    return 0;
}

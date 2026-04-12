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
#define FOR(i, a, b) for(ll i = a;i < b;i++)
#define For(i, a) FOR(i, 0, a)
#define REV(i, a, b) for(ll i = b-1;i >= a;i--)
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

ll comb(ll a,ll b){
  b=min(b,a-b);
  if(b<0||b>a){
    return 0;
  }
  ll ret=1;
  REP(b){
    ret*=(a-i);
  }
  REP(b){
    ret/=(i+1);
  }
  return ret;
}
void solve(string N, long long K){
  if(N.size()<K){
    cout<<0<<endl;
    return;
  }
  ll ans=0;
  ll tmp1=1;
  REP(K){
    tmp1*=9;
  }
  REP(N.size()-K){
    ans+=tmp1*comb(i+K-1,i);
  }
  dump(N.size());
  ll cur=0,i=0;
  while(cur<K&&i<N.size()){
    if(N[i]!='0'){
      ++cur;
      tmp1/=9;
      ans+=(N[i]-'1')*tmp1*comb(N.size()-cur,N.size()-K);
      if(i!=0){
        ans+=tmp1*9*comb(N.size()-i-1,N.size()-K-(i+1-cur+1));
      }
    }else{
    }
    ++i;
    dump(i);
    dump(ans);
  }
  dump(cur);
  if(cur==K){
    ++ans;
  }
  cout<<ans<<endl;
}

int main(){
  cout<<setprecision(1000);
  cin.tie(0);
  ios::sync_with_stdio(false);
    string N;
    cin>>N;
    long long K;
    cin>>K;
    solve(N, K);
    return 0;
}

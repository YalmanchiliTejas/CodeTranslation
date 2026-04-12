#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using vb=vector<bool>;
using vvb=vector<vb>;
using pii = pair<int,int>;
using pli = pair<ll,int>;
using pll = pair<ll,ll>;
using vpii = vector<pii>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define rep(i, n) for(int i=0;i<(int)n;i++)
#define rep2(i, s, n) for(int i=(s);i<(int)n;i++)
int INF=1e9+7;

ll power(ll a, int b) {
  if(!b) return 1;
  ll c = power(a, b/2);
  if(b%2) return c*c%INF*a%INF;
  return c*c%INF;
}

int main() {
  int N,M,K;
  cin >> N >> M >> K;
  
  vl fac(N*M+1);
  fac[0]=1;
  rep(i,N*M) fac[i+1]=fac[i]*(i+1)%INF;
  
  ll ans=0;
  rep(i,N) {
    rep(j,M) {
      if(i==0&&j==0) continue;
      if(i==0) ans+=(ll)N*(M-j)*j%INF*fac[N*M-2]%INF*power(fac[K-2]*fac[N*M-K]%INF,INF-2)%INF;
      else if(j==0) ans+=(ll)M*(N-i)*i%INF*fac[N*M-2]%INF*power(fac[K-2]*fac[N*M-K]%INF,INF-2)%INF;
      else ans+=(ll)(N-i)*(M-j)*2*(i+j)%INF*fac[N*M-2]%INF*power(fac[K-2]*fac[N*M-K]%INF,INF-2)%INF;
      ans%=INF;
    }
  }
  
  cout << ans << endl;
}
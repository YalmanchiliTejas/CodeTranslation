#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  ll N, K;
  cin>>N>>K;
  ll ans = 0;
  ll t;
  for(ll b=K+1;b<=N;++b) {
    t = (N+1)/b;
    ans += t*(b-K);
    if(t*b+K<=N) ans += (N-(t*b+K)+1);
  }
  if(K==0) ans -= N;
  cout<<ans<<endl;
}


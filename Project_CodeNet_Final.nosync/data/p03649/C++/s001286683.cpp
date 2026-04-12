#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF 1e18
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define rep(i,N) for(int i=0;i<N;i++)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin>>N;
  vector<ll>a(N);
  for(int i=0;i<N;i++)cin>>a[i];
  ll ans=0;
  while(true){
    ll s=0;
    for(int i=0;i<N;i++)s+=a[i]/N;
    ans+=s;
    for(int i=0;i<N;i++)a[i]=a[i]-(a[i]/N)*N+s-a[i]/N;
    bool ok=true;
    for(int i=0;i<N;i++)if(a[i]>=N)ok=false;
    if(ok)break;
  }
  cout<<ans<<endl;
  return 0;
}

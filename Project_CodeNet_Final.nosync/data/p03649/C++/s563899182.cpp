#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF=1e9,MOD=1e9+7;
const ll LINF=1e18;
using namespace std;
#define int long long

signed main(){
  int N;cin>>N;
  std::vector<int> v(N);
  for(int i=0;i<N;i++)cin>>v[i];
  sort(v.begin(),v.end());
  int ans=0;
  while(v[N-1]>N-1){
    int k=0;
    for(int i=0;i<N;i++){
      if(v[i]<=N-1)continue;
      int a=(v[i]-(N-1)-1)/N+1;
      k+=a;v[i]-=a*(N+1);
    }
    for(int i=0;i<N;i++)v[i]+=k;
    ans+=k;
    sort(v.begin(),v.end());
  }
  cout<<ans<<endl;
}


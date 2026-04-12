#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD=1e9+7;

signed main(){
  int n;cin>>n;
  vector<int> v(n);
  for(int i=0;i<n;i++)cin>>v[i];
  int ans=0,tmp=0;
  for(int i=n-1;i>=0;i--){
    (ans+=v[i]*tmp)%=MOD;
    (tmp+=v[i])%=MOD;
  }
  cout<<ans<<endl;
}

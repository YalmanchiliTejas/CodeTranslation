#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  while(cin>>n>>m,n+m){
    int t[20005];
    for(int i=0;i<n+m;++i)
      cin>>t[i];
    sort(t,t+n+m);
    int ans=t[0];
    for(int i=1;i<n+m;++i){
      ans=max(ans,t[i]-t[i-1]);
    }
    cout<<ans<<endl;
  }
  return 0;
}
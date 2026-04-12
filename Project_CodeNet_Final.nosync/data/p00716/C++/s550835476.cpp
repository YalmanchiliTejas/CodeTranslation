#include<bits/stdc++.h>
using namespace std;
int main(){
  int m; cin>>m;
  for(int i=0;i<m;++i){
    int a,b,n; cin>>a>>b>>n;
    int ans=0;
    for(int j=0;j<n;++j){
      double y;
      int tmp=a;
      int sum=0;
      int x,z; cin>>x>>y>>z;
      for(int k=0;k<b;++k){
        sum+=tmp*y;
        if(x) tmp+=tmp*y;
        tmp-=z;
      }
      ans=max(ans,sum+a-b*z);
    }
    cout<<ans<<endl;
  }
  return 0;
}
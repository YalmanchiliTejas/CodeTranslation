#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n;
  cin>>n;
  int d[n];
  for(int i=0;i<n;i++) cin>>d[i];
  map<int,int> m;
  int s=0,ans=0;
  for(int i=0;i<n;i++){
    s+=d[i];
    if(m.count(s)) ans=max(ans,i-m[s]);
    else m[s]=i;
    if(!s) ans=max(ans,i+1);
  }
  cout<<ans<<endl;
  return 0;
}
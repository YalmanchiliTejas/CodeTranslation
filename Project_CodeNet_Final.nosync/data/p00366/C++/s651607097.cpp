#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,t[100000],mx=-1;
  cin>>n;
  for(int i=0;i<n;i++)cin>>t[i],mx=max(mx,t[i]);
  vector<int> v;
  for(int i=1;i*i<=mx;i++)
    if(mx%i==0){
      v.push_back(i);
      v.push_back(mx/i);
    }
  int ans=0;
  for(int i=0;i<n;i++){
    int mn=1e9;
    for(int j=0;j<v.size();j++)
      if(v[j]>=t[i])mn=min(mn,v[j]-t[i]);
    ans+=mn;
  }
  cout<<ans<<endl;
  return 0;
}
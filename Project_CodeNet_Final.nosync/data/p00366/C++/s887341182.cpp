#include<bits/stdc++.h>
using namespace std;
using Int = long long;
signed main(){
  int n;
  cin>>n;
  vector<int> t(n);
  for(int i=0;i<n;i++) cin>>t[i];
  int m=*max_element(t.begin(),t.end());
  vector<int> v;
  for(int i=1;i<=m;i++)
    if(m%i==0) v.push_back(i);
  int ans=0;
  for(int i=0;i<n;i++)
    ans+=*lower_bound(v.begin(),v.end(),t[i])-t[i];
  cout<<ans<<endl;
  return 0;
}
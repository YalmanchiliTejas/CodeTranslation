#include<bits/stdc++.h>
using namespace std;
int n,m,a,ans;
vector<int> v;

int main(){
  while(1){
    cin>>n>>m;
    if(!n&&!m)break;
    v.push_back(0);
    for(int i=0;i<n;i++)
      cin>>a,v.push_back(a);
    for(int i=0;i<m;i++)
      cin>>a,v.push_back(a);
    sort(v.begin(),v.end());
    ans=0;
    for(int i=0;i<v.size()-1;i++)
      ans=max(ans,v[i+1]-v[i]);
    cout<<ans<<endl;
    v.clear();
  }
  return 0;
}
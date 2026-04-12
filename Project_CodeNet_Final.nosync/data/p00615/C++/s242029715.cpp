#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  while(cin>>n>>m,n||m){
    vector<int> v;v.clear();
    v.push_back(0);
    int i,j,k;
    int ans=0;
    for(i=0;i<n;i++){
      cin >>k;
      v.push_back(k);
    }
    for(i=0;i<m;i++){
      cin >>k;
      v.push_back(k);
    }
    sort(v.begin(),v.end());
    for(i=0;i<n+m;i++) ans=max(ans,v[i+1]-v[i]);
    cout << ans << endl; 
  }
  return 0;
}
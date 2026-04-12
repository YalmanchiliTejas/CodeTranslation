#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  while(cin>>a>>b,a+b){
    vector<int>v;
    for(int i=0;i<a+b;i++){
      int p;
      cin>>p;
      v.push_back(p);
    }
    sort(v.begin(),v.end());
    int ans=0,p=0;
    for(int i=0;i<a+b;i++){
      ans=max(ans,v[i]-p);
      p=v[i];
    }
    cout<<ans<<endl;
  }
}
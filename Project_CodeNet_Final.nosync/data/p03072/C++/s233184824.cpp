#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> h(n);
  for(int i=0;i<n;i++){
    cin>>h[i];
  }
  int t=0;
  int ans=0;
  for(int i=0;i<n;i++){
    t=max(t,h[i]);
    if(t==h[i]){
      ans++;
      
    }
  }
  cout<<ans<<endl;
  
  
}
#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
int main(){
  int n;
  cin>>n;
  int h[n];
  rep(i,n)cin>>h[i];
  int ans=0;
  for(int i=0;i<n;i++){
    bool f=true;
    for(int j=0;j<i;j++){
    
    if(h[i]<h[j])f=false;
    
      
  }
    if(f)ans++;
  }
  cout << ans <<endl;
}

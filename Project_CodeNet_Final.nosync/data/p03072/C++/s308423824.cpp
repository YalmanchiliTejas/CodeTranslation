#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
int main(){
  int n;
  cin>>n;
  int h[n];
  rep(i,n){
    cin>>h[i];
  }
  int k[n];
  rep(i,n){
    k[i]=1;
  }
  for(int i=1;i<n;i++){
    for(int j=0;j<i;j++){
      if(h[i]<h[j]){
        k[i]=0;
      }
    }
  }
  int ans=0;
  rep(i,n){
    ans+=k[i];
  }
  cout<<ans<<endl;
        
}
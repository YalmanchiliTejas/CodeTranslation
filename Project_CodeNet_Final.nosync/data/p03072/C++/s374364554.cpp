#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
  int n,h[20],ans=0;
  cin>>n;
  rep(i,n) cin>>h[i];
  rep(i,n){
    int b=0;
    for(int j=0;j<i;j++) if(h[i]>=h[j]) b++;
    if(b==i) ans++;
  }
  cout<<ans;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >>n;
  int h[n];
  for(int i=0;i<n;i++) cin>>h[i];
  int hi=0,ans=0;
  for(int i=0;i<n;i++) {
    if(h[i]>=hi){
      ans++;
      hi= max(hi,h[i]);
    }
  }
  cout<<ans<<endl;

  }

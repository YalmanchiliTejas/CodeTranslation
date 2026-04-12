#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,ans=1;
  cin>>n;
  vector<int> h(n);
  for(int i=0; i<n; i++) cin>>h[i];
  int lim=h[0];
  for(int i=1; i<n; i++){
    if(lim<=h[i]){
      ans++;
      lim=h[i];
    }
  }
  cout<<ans;
}
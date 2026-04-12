#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;


int main(){
  int n;cin>>n;
  vector<int> h(n);
  int mx=0,ans=0;
  rep(i,n){
    cin>>h[i];
    if(mx<=h[i]){
      ans ++;
      mx = max(mx,h[i]);
  }
  }
  cout << ans;
}



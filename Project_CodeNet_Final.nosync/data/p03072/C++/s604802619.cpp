#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
  int n;
  cin>>n;
  int h[n];
  rep(i,n){
    cin>>h[i];
  }
  int a=h[0];
  int ans=0;
  rep(i,n){
    if(a<=h[i]){
      ans++;
      a=h[i];
    }
  }
  cout<<ans<<endl;
}
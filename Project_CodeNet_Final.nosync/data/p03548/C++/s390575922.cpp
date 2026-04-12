#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int x,y,z;cin>>x>>y>>z;
  x-=z;
  int ans=x/(y+z);
  cout<<ans<<endl;
}
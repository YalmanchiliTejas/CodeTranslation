#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; typedef long long ll; const int M = 998244353;

int main() {
  int n,s; cin>>n>>s;
  int a[n]; for(int i=0;i<n;i++) cin>>a[i];
  ll u[s+1]; fill(u,u+s+1,0); ll an=0;
  for(int i=0;i<n;i++) {
    int e=a[i];
    if (e == s) {
      an += (i+1) * (n-i); an%=M;
      continue;
    }
    for(int j=s;j>=e && j-e>=0;j--) {
      if (j == s) {
        an += u[s-e] * (n-i); an%=M;
      }
      if (u[j-e] > 0) u[j] += u[j-e];
      if (j-e == 0) u[j] += (i+1);
      u[j] %= M;
    }
    //for(int j=0;j<s;j++) cout<<u[j]<<" "; cout<<endl;
  }
  cout<<an<<endl;
}
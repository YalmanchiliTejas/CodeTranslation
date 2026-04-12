#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0;i < n;i++)
#define repr(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)

int main(){
  int x,y,z;
  cin>>x>>y>>z;
  int s=y+z;
  int ans=(x-z)/s;
  cout<<ans<<endl;
  return 0;
}
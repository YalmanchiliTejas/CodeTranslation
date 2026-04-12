#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main() {
  int X,Y,Z; cin >>X >>Y >>Z;
  int ans=X/(Y+Z);
  if (ans*(Y+Z)+Z<=X) cout <<ans <<endl;
  else cout <<ans-1 <<endl;
  return 0;
}

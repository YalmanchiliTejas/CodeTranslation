#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
#define rep(i, j, n) for (int i = j; i < n; i++)
#define out(ans) cout << ans << endl;
const long long mod = 1e9 + 7;

int main(){

  int x,y,z;cin>>x>>y>>z;

  for(int i=0;;i++){
    if((i+1)*z+y*i>x){
      out(i-1);
      return 0;
    }
  }

  return 0;
}

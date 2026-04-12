#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i < n; i++)
#define reps(i, n) for(int i=1; i <= n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()

using namespace std;
using ll=long long;


int main() {
  int x,y,z;
  cin >> x >> y >> z;
  int w= x-z;
  int ans=0;

  while(true){
    if(w<(y+z))break;
    w-=(y+z);
    ans++;
  }
  cout << ans;
}
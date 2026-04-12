#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const ll INF = 1LL<<60;
const int ny[4] = {-1,1,0,0}, nx[4] = {0,0,-1,1};
int sy,sx,gy,gx;

int main(){
  int x,y,z; cin >> x >> y >> z;
  x -= z;
  int ans = 0;
  while(x >= y+z){
    ans++;
    x -= y+z;
  }
  cout << ans << endl;
  return 0;
}

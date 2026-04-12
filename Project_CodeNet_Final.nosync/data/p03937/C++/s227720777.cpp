#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int INF = 1000000001;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> g(h+2, vector<char>(w+2, '.'));
  for(int i = 1; i <= h; ++i){
    for(int j = 1; j <= w; ++j){
      cin >> g[i][j];
    }
  }

  for(int i = 1; i <= h; ++i){
    for(int j = 1; j <= w; ++j){
      if(g[i][j] != '#') continue;
      if( (g[i+1][j] == '#' && g[i][j+1] == '#') ||
          (g[i-1][j] == '#' && g[i][j-1] == '#') ){
        cout << "Impossible" << endl;
        return 0;
      }
    }
  }
  cout << "Possible" << endl;
  return 0;
}

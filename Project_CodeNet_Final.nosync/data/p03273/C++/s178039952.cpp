#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double Double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

char c[101][101];
int main() {
  int H,W;
  cin >> H >> W;
  vector<int> x;
  vector<int> y;
  for(int i = 0 ; i < H ; i++){
    for(int j = 0 ; j < W ; j++){
      cin >> c[i][j];
      if( c[i][j] == '#' ) x.push_back(j), y.push_back(i);
    }
  };
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  x.erase(unique(x.begin(), x.end()), x.end());
  y.erase(unique(y.begin(), y.end()), y.end());
  for( auto i : y ){
    for(auto j : x ){
      cout << c[i][j];
    }
    cout << endl;
  }


  return 0;
}

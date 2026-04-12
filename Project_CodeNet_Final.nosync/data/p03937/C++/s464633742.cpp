#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<set>
#include<map>
#include<queue>
#include<cstring>
#include<sstream>
using namespace std;

typedef long long ll;

int main() {
  int H,W;
  string s[9];
  cin >> H >> W;
  for ( int i = 0; i < H; i++ ) {
    cin >> s[i];
  }

  int cnt = 0;
  for ( int i = 0; i < H; i++ ) {
    for ( int j = 0; j < W; j++ ) {
      if ( s[i][j] == '#' ) cnt++;
    }
  }

  if ( cnt == H+W-1 ) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
  return 0;
}

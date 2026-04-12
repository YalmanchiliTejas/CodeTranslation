#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  string s;
  while ( cin >> s, s != "#" ) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--; b--; c--; d--;

    bool dat[9][9] = {{0}};
    int h = 1, w = 0;
    {
      int y = 0, x = 0;
      for ( int i = 0; i < (int)s.size(); i++ ) {
	if ( s[i] == 'b' ) {
	  if ( !y ) w++;	  
	  dat[y][x] = 1;
	  x++;
	} else if ( s[i] == '/' ) {
	  h++;
	  x = 0;
	  y++;
	} else {
	  if ( !y ) w += s[i]-'0';	  
	  x += s[i]-'0';	  
	}
      }
    }

    swap(dat[a][b], dat[c][d]);
    for ( int i = 0; i < h; i++ ) {
      int cnt = 0;
      for ( int j = 0; j < w; j++ ) {
	if ( dat[i][j] ) {
	  if ( cnt ) cout << cnt;
	  cout << 'b';
	  cnt = 0;
	} else {
	  cnt++;
	}
      }
      if ( cnt ) cout << cnt;
      if ( i < h-1 ) cout << '/';      
    }
    cout << endl;
  }
  
  return 0;
}


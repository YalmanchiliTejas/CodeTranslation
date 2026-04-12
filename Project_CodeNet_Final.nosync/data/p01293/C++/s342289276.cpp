#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

  while( true ) {

    char s;
    cin >> s;
    if ( s == '#' ) break;

    vector< vector< pair< long long int, char > > > v;

    for ( long long int p = 0; p < 4; p++ ) {
      vector< pair< long long int, char > > vp;
      for ( long long int t = 0; t < 13; t++ ) {

	string in;
	cin >> in;

	long long int k = in[0] - '0';
	if ( in[0] == 'A' ) {
	  k = 14;
	}else if ( in[0] == 'K' ) {
	  k = 13;
	}else if ( in[0] == 'Q' ) {
	  k = 12;
	}else if ( in[0] == 'J' ) {
	  k = 11;
	}else if ( in[0] == 'T' ) {
	  k = 10;
	}

	vp.push_back( make_pair( k, in[1] ) );

      }
      v.push_back( vp );
    }

    long long int cnt = 0;
    long long int k = 0;

    for ( long long int t = 0; t < 13; t++ ) {

      char suit = v[k][t].second;
      for ( long long int i = 0; i < 4; i++ ) {
	if ( v[i][t].second == s ) suit = s;
      }
      long long int win = -1;
      long long int max_num = -1;
      for ( long long int i = 0; i < 4; i++ ) {
	if ( v[i][t].second == suit && v[i][t].first > max_num ) {
	  win = i;
	  max_num = v[i][t].first;
	}
      }

      if ( win == 0 || win == 2 ) cnt++;
      k = win;

    }

    if ( cnt > 6 ) {
      cout << "NS " << cnt - 6 << endl;
    }else {
      cout << "EW " << 7 - cnt << endl;
    }

  }

  return 0;

}
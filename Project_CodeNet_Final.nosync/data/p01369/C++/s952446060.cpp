#include<bits/stdc++.h>
using namespace std;

int ret_place( char c )
{
  c -= 32;
  if( c == 'Q' || c == 'W' || c == 'E' || c == 'R' || c == 'T' || c == 'A' || c == 'S' ||c == 'D' || c == 'F' || c == 'G' || c == 'Z' || c == 'X' || c == 'C' || c == 'V' || c == 'B' ) return 0;
  else return 1;
}

int main()
{
  string s;
  while( cin >> s, s != "#" ) {
    int now = ret_place( s[0] ); //0:l 1:r
    int cnt = 0;
    for(int i=1; i<s.size(); i++) {
      int res = ret_place( s[i] );
      if( now != res ) cnt++, now = res;  
    }

    cout << cnt << endl;
  }
}
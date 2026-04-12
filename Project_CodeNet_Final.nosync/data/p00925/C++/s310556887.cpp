#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);
  
  string s;
  int l;
  cin >> s;
  l = s.size();

  int n;
  cin >> n;

  int res1 = 0, res2 = 0;

  for ( int i = 0; i < l; i++ ) {
    if ( s[i+1] == '+' || i == l-1 ) {
      res1 += s[i]-'0';
      i++;      
    } else {
      int m = s[i]-'0';
      i += 2;      
      while ( s[i-1] == '*' ) {
	m *= s[i]-'0';
	i += 2;	
      }
      res1 += m;
      i--;      
    }    
  }

  res2 = s[0]-'0';  
  for ( int i = 2; i < l; i++ ) {
    if ( s[i-1] == '*' ) {
      res2 *= s[i]-'0';      
      i++;      
    } else {
      res2 += s[i]-'0';
      i++;      
    }
  }

  if ( res1 == n && res2 == n ) {
    puts("U");    
  } else if ( res1 == n ) {
    puts("M");    
  } else if ( res2 == n ) {
    puts("L");    
  } else {
    puts("I");    
  }  
  
  return 0;
}


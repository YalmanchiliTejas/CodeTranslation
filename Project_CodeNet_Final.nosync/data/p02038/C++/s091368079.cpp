#include<bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  char c;
  cin >> c;
  bool b = ( c == 'T' );
  for(int i=1;i<n;++i) {
    cin >> c;
    if( b == false ) b = true;
    else b = ( c == 'T' );
  }
  puts(b?"T":"F");
  return 0;
}


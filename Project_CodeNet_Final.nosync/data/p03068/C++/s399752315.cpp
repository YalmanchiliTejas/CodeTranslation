#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  int n,k;
  
  cin >> n >> s >> k;
  
  for( int i=0; i<n; i++){
    if( s[i] != s[k-1] ) s[i]='*';
  }
  
  cout << s << endl;
  return 0;
}
#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  string S;
  cin >> S;
  
  for( int i = 1; i < S.size(); i++ ){
    if( S.at(i-1) == 'A' && S.at(i) == 'C' ){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  

}

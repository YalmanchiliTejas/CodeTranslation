#include <bits/stdc++.h>
// #define int long long
using namespace std;

signed main() {
  int N, K;
  string S;
  cin >> N >> S >> K;
  
  char n = S.at(K-1);
  
  for( int i = 0; i < S.size(); i++ ){
    if( S.at(i) != n ){
      S.replace(i, 1, 1, '*');
    }
  }
  cout << S << endl;
      
}

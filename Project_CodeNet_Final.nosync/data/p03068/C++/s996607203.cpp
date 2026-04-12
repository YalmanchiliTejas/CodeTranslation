#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K;
  string S;
  
  cin >> N >> S >> K;
  char C = S.at(K-1);
  
  for( int i = 0 ; i < N ; i++ ){
  	if ( S.at(i) != C )
      S.at(i) = '*';
  }  
  cout << S << endl;  
}
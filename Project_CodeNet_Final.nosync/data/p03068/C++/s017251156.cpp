#include<bits/stdc++.h>
using namespace std;

int main() {
  int N; string S; int K;
  cin >> N >> S >> K;
  char A = S.at(K-1);
  for( int i = 0; i < N; i++ ) {
    if( S.at(i) != A )
      S.at(i) = '*';
  }
  cout << S << endl;
}
#include<bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  int visible,unvisible;
  vector<int> height(N);
  
  for( int i = 0; i < N; i++ )
    cin >> height.at(i);
  
  for( int i = 1; i < N + 1; i++ ) {
    for( int j = 1; j < i; j++ ) {
      unvisible = 0;
      if( height.at(i-1) < height.at(j-1) ) {
        unvisible++;
        break;
      }
    }
    if( unvisible == 0 )
      visible++;
  }
  cout << visible << endl;
}
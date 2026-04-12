#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> H(N);
  for( int i = 0; i < N; i++ ) cin >> H.at(i);
  
  int saidai = 0;
  int count = 0;
  for( int i = 0; i < N; i++ ){
    if( saidai <= H.at(i) ){
      count++;
      saidai = H.at(i);
    }
  }
  cout << count << endl;
}

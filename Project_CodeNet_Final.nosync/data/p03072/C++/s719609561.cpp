#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  for( int i = 0; i < N ; i++) {
    cin >> vec.at(i);
  }
  int inn = 0;
  int highest = vec.at(0);
  for( int i = 0; i < N ; i++) {
    if (vec.at(i) >= highest) {
      inn ++;
      highest = vec.at(i);
    }
  }
  cout << inn << endl;
}

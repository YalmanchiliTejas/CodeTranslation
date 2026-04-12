#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  
  for (int i = 0; i < N; i++) {
    cin >> vec.at(i);
  } //山の高さを入力
  
  int count = 0;
  
  for (int i = 0; i < N; i++) {
    int x = 0;
    
    for (int k = 0; k <= i; k++) {
      if (vec.at(i) >= vec.at(k)) {
        x++;
      } 
    } // vec.at(i)以下のkの個数を数える

    if (x == i + 1) {
      count++;
    }
  }
  
  cout << count << endl;
}

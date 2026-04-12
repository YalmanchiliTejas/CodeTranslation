#include <bits/stdc++.h>
using namespace std;

int main() {
  // 入力
  int N;
  cin >> N;
  vector<int> h(N);
  for (int i = 0; i < N; i++) {
    cin >> h.at(i);
  }
  
  // 判定
  bool judge = true;
  int count = 0;
  for (int i = 0; i < N; i++) {
    judge = true;
  	for (int j = 0; j < i; j++) {
   	  if (h.at(i) < h.at(j)) {
        judge = false;
        break;
      }
    }
    if (judge) {
      count++;
    }
  }
  
  // 出力
  cout << count << endl;
  
  return 0;
}
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

template <class T> void dump(const vector<T>& vec) {
  for(const T& value : vec) {
    cout << value << " ";
  }
  cout << endl;
}

int main() {
  int n;
  cin >> n;
  
  // できるだけ大きい色を塗りたい
  // 1 100 2 101 3 103 だと
  // 1 100 101 102, 2 3 の2色にする
  // 2分探索して、
  // 1. 最小の末尾より小さい場合は、新しい色
  // 2. それ以外は、見つかる中で最大の末尾に追加
  
  vector<int> colors; // 各色の現在の最大値を保管。降順に並ぶ
  int a;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    auto ite = upper_bound(colors.begin(), colors.end(), a, greater<>());
    if (ite == colors.end()) {
      colors.push_back(a);
    } else {
      *ite = a;
    }
    
    // dump(colors);
  }

  cout << colors.size() << endl;

  return 0;
}
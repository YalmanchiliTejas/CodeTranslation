#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> H;
  
  int result = 1;
  int h;
  cin >> h;
  H.push_back(h);
  for (int i = 1; i < N; i++) {
    cin >> h;
    int tmp = 1;
    for (int j = 0; j < H.size(); j++) {
      if (h < H[j]) tmp = 0;
    }
    result += tmp;
    H.push_back(h);
  }
  cout << result << endl;
  return 0;
}
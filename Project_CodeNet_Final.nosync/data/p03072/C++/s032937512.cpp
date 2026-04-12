#include <iostream>
using namespace std;

template <class T> inline bool chmax(T& a, T b) {
  if(a <= b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  int N;
  cin >> N;
  int max = 0;
  int ans = 0;
  int h;
  for(int i = 0; i < N; ++i) {
    cin >> h;
    if(chmax(max, h)) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
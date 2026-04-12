#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int N; cin >> N;
  int cnt = 0, prev = 0;
  for (int i = 0; i < N; ++i) {
    int h; cin >> h;
    if (prev <= h) {
      prev = h;
      ++cnt;
    }
  }
  cout << cnt << endl;
}

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  int64_t N;
  cin >> N;

  cout << N * 800 - (N / 15) * 200 << endl;

  return 0;
}

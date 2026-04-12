#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  int N;
  cin >> N;
  int H[N];
  for(int i = 0; i < N; ++i)
    cin >> H[i];

  int maxMT = H[0], cnt = 1;
  for(int i = 1; i < N; ++i) 
    if(H[i] >= maxMT) {
      maxMT = H[i];
      ++cnt;
    }
  cout << cnt << endl;
  return 0;
}



#include <iostream>
#include <string>

#include <algorithm>

using namespace std;

int main() {
  //
  int N;
  cin >> N;
  int H[N];
  for (int i = 0; i < N; ++i) {
    cin >> H[i];
  }

  int max_h = H[0], num = 1;
  for (int i = 1; i < N; ++i) {
    if(H[i] >= max_h){
      max_h = max(H[i], max_h);
      num++;
//      printf("[%d] %d, %d\n", i, H[i], max_h);
//      cout << i << " - " << H[i] << endl;
    }
  }

  cout << num << endl;



  return 0;
}
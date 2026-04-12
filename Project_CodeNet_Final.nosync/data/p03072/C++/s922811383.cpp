#include <vector>
#include <iostream>

using namespace std;

int main(void) {
  int N, i, j;
  
  cin >> N;
  
  vector <int> H;

  for (i = 0; i < N; i++) {
    int h;
    cin >> h;
    H.push_back(h);
  }

  int c, mx;
  
  c = 0;
  mx = 0;
  for (i = 0; i < N; i++) {
    if (mx <= H[i]) {
      c++;
      mx = H[i];
    }
  }
  cout << c << endl;
  return 0;

}

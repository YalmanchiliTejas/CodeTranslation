#include <iostream>
using namespace std;



int main() {

  int N;
  cin >> N;
  
  int H[N];
  for (int i = 0; i < N; i++) {
    cin >> H[i];
  }
  
  int ans = 1;
  int check = H[0];
  for (int i = 1; i < N; i++) {
    if(check <= H[i]) {
      ans++;
      check = H[i];
    }
  }
  
  cout << ans << endl;

  return 0;
}

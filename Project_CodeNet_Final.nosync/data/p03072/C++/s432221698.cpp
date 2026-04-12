#include <iostream>
using namespace std;
int main() {
  int n, H, max, cnt;
  int result;
  cin >> n;
  max = 0;
  cnt = 0;
  for(int i = 0; i < n; i++){
      cin >> H;
      if(H >= max){
          max = H;
          cnt++;
      }
  }

  cout << cnt << endl;
  return 0;
}
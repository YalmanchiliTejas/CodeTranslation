#include <iostream>

using namespace std;

int main(){
  int N, h, ans = 0, max = -1;
  cin >> N;
  for (int i=0; i<N; i++){
    cin >> h;
    if (h >= max){
      ans++;
      max = h;
    }
  }
  
  cout << ans << endl;
  return 0;
}
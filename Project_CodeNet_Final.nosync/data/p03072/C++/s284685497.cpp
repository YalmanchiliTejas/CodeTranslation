#include <iostream>

using namespace std;
int main(){
  int N;
  int H[100];

  cin >> N;
  for(int i = 0; i < N; i++) cin >> H[i];

  int ans = 0;
  int max_H = 0;
  for(int i = 0; i < N; i++){
    if(max_H <= H[i]){
      max_H = H[i];
      ans += 1;
    }
  }
  cout << ans << endl;
}
    
#include<iostream>
using namespace std;
int main(void){
  int N;
  cin >> N;
  int M = -1;
  int ans = 0;
  for(int i = 0; i < N; i++){
    int H;
    cin >> H;
    if(M <= H){
      M = H;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}

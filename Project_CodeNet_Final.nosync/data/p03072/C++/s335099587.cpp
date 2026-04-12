#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,H;
  cin >> N;
  int HM = 0;
  int ans = 0;
  for (int i = 0; i < N; i++){
    cin >> H;
    if (H >= HM){
      ans++;
      HM = H;
    }
  }
  cout << ans;
}
#include <bits/stdc++.h>
using namespace std;

int main(){

  int N;
  cin >> N;
  vector<int> H(N);

  //旅館の数を入力
  for (int i =0; i < N; i++){
    cin >> H.at(i);
  }

  //海が見える旅館を数える
  int ans = 0;
  for(int i = 0; i < N; i++){
    bool hhh = true;
    for(int j = 0; j < i; j++){
      if(H.at(i) < H.at(j)){
        hhh = false;
        break;
      }
    }
    if(hhh){
      ++ans;
    }
  }

  cout << ans << endl;
}

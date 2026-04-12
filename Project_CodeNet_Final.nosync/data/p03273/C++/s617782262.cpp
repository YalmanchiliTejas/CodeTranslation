#include<bits/stdc++.h>

using namespace std;

int main(void){
  int H, W;
  cin >> H >> W;
  vector<string> a(H);
  vector<int> h(H), w(W);
  for(int i = 0; i < H; i++){
    cin >> a[i];
    for(int j = 0; j < W; j++){
      if(a[i][j] == '#'){
        h[i]++;
        w[j]++;
      }
    }
  }
  for(int i = 0; i < H; i++){
    if(h[i] == 0) continue;
    for(int j = 0; j < W; j++){
      if(w[j] == 0) continue;
      cout << a[i][j];
    }
    cout << endl;
  }
  return 0;
}

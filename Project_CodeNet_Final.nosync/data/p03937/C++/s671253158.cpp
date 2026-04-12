#include<bits/stdc++.h>
using namespace std;

#define debug(n) cerr << #n << ':' << n << endl;

int main(){
  int H,W; cin >> H >> W;
  int cnt = 0;
  for(int i = 0; i < H; ++i){
    for(int j = 0; j < W; ++j){
      char c; cin >> c;
      if(c == '#')cnt++;
    }
  }  
  cout << (cnt == H + W - 1?"Possible\n":"Impossible\n");
  return 0;
}

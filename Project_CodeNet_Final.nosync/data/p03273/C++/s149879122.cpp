#include<iostream>
#include<vector>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;

  vector<string> a(H);
  for(int i = 0; i < H; i++){
    cin >> a[i];
  }

  vector<int> hs, ws;
  for(int h = 0; h < H; h++){
    bool has_black = false;
    for(int w = 0; w < W; w++){
      if(a[h][w] == '#'){
        has_black = true;
      }
    }
    if(has_black){
      hs.push_back(h);
    }
  }

  for(int w = 0; w < W; w++){
    bool has_black = false;
    for(int h = 0; h < H; h++){
      if(a[h][w] == '#'){
        has_black = true;
      }
    }
    if(has_black){
      ws.push_back(w);
    }
  }

  for(auto h: hs){
    for(auto w: ws){
      cout << a[h][w];
    }
    cout << endl;
  }
}

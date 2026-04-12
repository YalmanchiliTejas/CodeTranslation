#include <iostream>
#include <vector>
using namespace std;
int main(){
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  vector<bool> h(H,false), w(W,false);
  for(int i = 0; i < H; ++i){
    cin >> S[i];
    for(int j = 0; j < W; ++j){
      if(S[i][j] == '.') continue;
      h[i] = true;
      w[j] = true;
    }
  }
  vector<string> ans;
  for(int i = 0; i < H; ++i){
    if(not h[i]) continue;
    string t;
    for(int j = 0; j < W; ++j){
      if(w[j]) t += S[i][j];
    }
    ans.push_back(t);
  }
  for(auto s : ans) cout << s << endl;
}

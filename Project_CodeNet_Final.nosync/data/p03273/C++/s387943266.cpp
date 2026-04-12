#include <bits/stdc++.h>
using namespace std;

int main(){
  int i, j, H, W;
  cin >> H >> W;
  
  vector<string> A(H);
  for(i = 0; i < H; i++){
  	cin >> A.at(i);
  }
  vector<int> h(H), w(W);
  for(i = 0; i < H; i++){
    for(j = 0; j < W; j++){
  		if(A.at(i).at(j) == '#') break;
      	if(j == W-1) h.at(i) = 1;
    }
  }
  for(i = 0; i < W; i++){
    for(j = 0; j < H; j++){
  		if(A.at(j).at(i) == '#') break;
      	if(j == H-1) w.at(i) = 1;
    }
  }
  for(i = 0; i < H; i++){
    for(j = 0; j < W; j++){
      if(h.at(i) == 0 && w.at(j) == 0) cout << A.at(i).at(j);
    }
    if(h.at(i) == 0) cout << endl;
  }
}
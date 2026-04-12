#include <bits/stdc++.h>
using namespace std;

int main() {
	int H, W;
  cin >> H >> W;
  vector<string> data(H);
  for(int i=0;i<H; i++){
    cin >> data.at(i);
  }
  
  // 除去するべき行を抜く
  vector<string> data1;
  for(int i=0; i<H; i++){
    int dotCount = 0;
    for(int j=0;j<data.at(i).size();j++){
      if (data.at(i).at(j) == '.') { dotCount++; }
    }
    if (dotCount == W) {
      continue;
    }
    data1.push_back(data.at(i));
  }

  // 縦の除去するべき文字をxでマーク
  for(int j=0;j<W;j++){
    int dotCount = 0;
    for(int i=0; i<data1.size(); i++) {
      if(data1.at(i).at(j) == '.') { dotCount++; }
    }
    if (dotCount == data1.size()) {
      for(int i=0; i<data1.size(); i++) {
        data1.at(i).at(j) = 'x';
      }
    }
  }
  
  for(int i=0;i<data1.size(); i++){
    string nl;
    for(int j=0; j<W; j++){
      if(data1.at(i).at(j) != 'x') {
        nl.push_back(data1.at(i).at(j));
      }
    }
    data1.at(i) = nl;
  }
  
  for(int i=0;i<data1.size();i++){
    cout << data1.at(i) << endl;
  }
}

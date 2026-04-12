#include <bits/stdc++.h>
using namespace std;
int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> vec(H, vector<char>(W));
  for(int i=0; i<H; i++) {
    for(int j=0; j<W; j++) {
      cin >> vec.at(i).at(j);
    }
  }
  int cnt=0, cnt2=0;
  for(int i=0; i<H; i++) {
    for(int j=0; j<W; j++) {
      if(vec.at(i).at(j)=='.'||vec.at(i).at(j)=='0') {
        cnt++;
      }
      if(j==W-1&&cnt==W) {
        for(int k=0; k<W; k++) {
          vec.at(i).at(k)='0';
        }
      }
    }
    cnt=0;
  }
  for(int i=0; i<W; i++) {
    for(int j=0; j<H; j++) {
      if(vec.at(j).at(i)=='.'||vec.at(j).at(i)=='0') {
        cnt++;
      }
      if(j==H-1&&cnt==H) {
        cnt2++;
        for(int k=0; k<H; k++) {
          vec.at(k).at(i)='0';
        }
      }
    }
    cnt=0;
  }
  for(int i=0; i<H; i++) {
    for(int j=0; j<W; j++) {
      if(vec.at(i).at(j)!='0') {
        cout << vec.at(i).at(j);
        cnt++;
      }
      if(W-cnt2==cnt) {
        cout << endl;
        cnt=0;
      }
    }
  }
}
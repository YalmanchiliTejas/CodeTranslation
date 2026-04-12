#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H,W,cnt=0;
  cin >> H >> W;
  vector<vector<char>> data(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
	  for (int j = 0; j < W; j++) {
	    cin >> data.at(i).at(j);
      }
  }
  for (int i = 0; i< W; i++) {
    for (int j= 0; j<H ;j++) {
      if(data.at(j).at(i)=='.' ||data.at(j).at(i)=='X')
        cnt++;
    }
    if(cnt==H){
      for (int j= 0; j<H ;j++) {
        data.at(j).at(i)='Y';
      }
    }
    cnt=0;
  }  
  for (int i = 0; i< H; i++) {
    for (int j= 0; j<W ;j++) {
      if(data.at(i).at(j)=='.'||data.at(i).at(j)=='Y')
        cnt++;
    }
    if(cnt==W){
      for (int j= 0; j<W ;j++) {
        data.at(i).at(j)='X';
      }
    }
    cnt=0;
  }  

  for (int i = 0; i< H; i++) {
    for (int j= 0; j<W ;j++) {
      if(data.at(i).at(j)!='X'&&data.at(i).at(j)!='Y')
		  cout<<data.at(i).at(j);
      if (j== W-1&&data.at(i).at(j)!='X')
        cout << endl;
    }
  }  
}
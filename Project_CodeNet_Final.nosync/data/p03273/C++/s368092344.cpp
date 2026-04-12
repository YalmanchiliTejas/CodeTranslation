#include <bits/stdc++.h>
using namespace std;

int main() {
  // input hight and width
  int H, W;
  cin >> H >> W;
 
  // input table
  vector<vector<char>> table(H, vector<char>(W));
  
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> table.at(i).at(j);
    }
  }
  
  // check white('.') line
  vector<int> cnt_w(H,0),cnt_h(W,0);
  
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(table.at(i).at(j)=='.')
        cnt_w.at(i)++;
    } 
  }
 
  for(int i=0;i<W;i++){
    for(int j=0;j<H;j++){
      if(table.at(j).at(i)=='.')
        cnt_h.at(i)++;
    } 
  }


  // display result table
   for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(cnt_w.at(i)!=W && cnt_h.at(j)!=H)// not white line
        cout << table.at(i).at(j);
      if(cnt_w.at(i)!=W && j==W-1)
        cout << endl;
    }
  } 
  
}

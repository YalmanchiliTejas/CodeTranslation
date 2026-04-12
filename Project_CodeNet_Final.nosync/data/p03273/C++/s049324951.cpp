#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> tbl (h, vector<char>(w));
  
  //入力
  for(int i=0; i<h; i++)
    for(int j=0; j<w; j++)
      cin >> tbl.at(i).at(j);
  
  //縦処理
  for(int i=0; i<w; i++){
    int cnt=0;
    for(int j=0; j<h; j++){
      if(tbl.at(j).at(i) == '.')
        cnt++;
      else
        break;
    }
  	if(cnt == h){
      //cout << "????????" << endl;
      for(int j=0; j<h; j++)
        tbl.at(j).at(i) = '?';
    }
  }
  
  //横処理
  for(int i=0; i<h; i++){
    int cnt=0;
    for(int j=0; j<w; j++){
      if(tbl.at(i).at(j) == '#')
        break;
      else
        cnt++;
    }
  	if(cnt == w){
      for(int j=0; j<w; j++)
        tbl.at(i).at(j) = '!';
    }
  }
  

  /*
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      cout << tbl.at(i).at(j);
      if(j < w - 1)
        cout << ' ';
      else
        cout << endl;
    }
  } */
  
   //出力
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      if(tbl.at(i).at(j) == '!'){
        break;
      }else if(tbl.at(i).at(j) == '?'){
        if(j == w - 1)
			cout << endl;
      }
      else{
      	cout << tbl.at(i).at(j);      
		  if(j == w - 1)
			cout << endl;
      }
    }
  }
}

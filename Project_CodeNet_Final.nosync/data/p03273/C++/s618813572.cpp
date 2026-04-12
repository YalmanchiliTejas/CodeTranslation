#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  vector<vector<char>> a(H, vector<char>(W));
  for(int i=0;i<H;i++){
  	for(int j=0;j<W;j++){
    cin >> a.at(i).at(j);
    }
  }
  vector<vector<int>> data(H, vector<int>(W));
  for(int i=0;i<H;i++){
    int count=0;
  		for(int j=0;j<W;j++){
      		if(a.at(i).at(j) == '#') count++;
		 }
      if(count>=1) for(int k=0;k<W;k++) data.at(i).at(k) +=1;
  }

  for(int j=0;j<W;j++){
    int count=0;
  		for(int i=0;i<H;i++){
      		if(a.at(i).at(j) == '#') count++;
		 }
      if(count>=1) for(int k=0;k<H;k++) data.at(k).at(j) +=1;
  }
  
  for(int i=0;i<H;i++){
    int count=0;//開業のため追加
  	for(int j=0;j<W;j++){
    if(data.at(i).at(j)>=2) cout <<  a.at(i).at(j);
    if(a.at(i).at(j) == '#') count++;//開業のため追加
    }
   if(count>=1) cout << endl;//開業のため追加
  }
} 
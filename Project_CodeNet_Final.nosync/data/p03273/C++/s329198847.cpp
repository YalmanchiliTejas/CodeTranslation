#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >>H>> W;

  vector<vector<char>> vec(H,vector<char>(W));

  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      cin>>vec.at(i).at(j);
    }
  }
  bool a=false;
  int x=0;
  int z=0;
  vector<vector<char>> ans(H);
  vector<vector<char>> lo(H);
  for(int i=0; i<H; i++){
    int a=0;
    for(int j=0; j<W; j++){
      if(vec.at(i).at(j)=='.')
      a++;
      
      if(a==W)
      x++;
      if(a!=W&&j==W-1){
        for(int k=0; k<W; k++){
          ans.at(i-x).push_back(vec.at(i).at(k));
        }
      }
    }
  }
  for(int i=0; i<W; i++){
    int a=0;
    for(int j=0; j<H-x; j++){
      if(ans.at(j).at(i)=='.')
      a++;

      if(a==H-x)
      z++;
      if(a!=H-x&&j==H-x-1){
        for(int k=0; k<H-x; k++)
        lo.at(k).push_back(ans.at(k).at(i));
      }
    }
  }
  for(int i=0; i<H-x; i++){
    for(int j=0; j<W-z; j++){
      cout<<lo.at(i).at(j);
      if(j==W-z-1)
      cout<<endl;
    }
  }
}

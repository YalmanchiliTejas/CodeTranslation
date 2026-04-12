#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  vector<vector<char>> a(H,vector<char>(W));
  for(int i=0;i<H;i++)
    for(int j=0;j<W;j++)
      cin >> a.at(i).at(j);
  vector<vector<bool>> b(1,vector<bool>(H,true));
  b.push_back(vector<bool>(W,true));
  for(int i=0;i<H;i++){
    int j=0;
    for(;j<W;j++)
      if(a.at(i).at(j)=='#')
        break;
    if(j==W)
      b.at(0).at(i)=false;
  }
  for(int i=0;i<W;i++){
    int j=0;
    for(;j<H;j++)
      if(a.at(j).at(i)=='#')
        break;
    if(j==H)
      b.at(1).at(i)=false;
  }
  for(int i=0;i<H;i++)
    if(b.at(0).at(i)){
      for(int j=0;j<W;j++)
        if(b.at(1).at(j))
          cout << a.at(i).at(j);
      cout << endl;
    }
}
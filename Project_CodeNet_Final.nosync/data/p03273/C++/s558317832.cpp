#include <bits/stdc++.h>
using namespace std;

int main()
{
  int H, W;
  cin >> H >> W;
  
  vector<vector<char>> grids(H, vector<char>(W));
  
  // 入力
  for(int i = 0; i < H; ++i)
  {
    for(int j = 0; j < W; ++j)
    {
      cin >> grids.at(i).at(j);
    }
  }
  
  // 行削除
  vector<char> deleterow(W, '.');
  for(int i = grids.size() - 1; i >= 0; --i)
  {
    if(grids.at(i) == deleterow)
    {
      grids.erase(grids.begin() + i);
    }
  }
  
  // 列削除
  vector<int> deleteclmnum;
  for(int i = 0; i < W; ++i)
  {
    bool flg = true;
    for(int j = 0; j < grids.size(); ++j)
    {
      if(grids.at(j).at(i) != '.')
      {
        flg = false;
      }
    }
    
    if(flg)
    {
      deleteclmnum.push_back(i);
    }
  }
  sort(deleteclmnum.rbegin(), deleteclmnum.rend());
  
  for(int i = 0; i < grids.size(); ++i)
  {
    for(int j = 0; j < deleteclmnum.size(); ++j)
    {
      grids.at(i).erase(grids.at(i).begin() + deleteclmnum.at(j));
    }
  }
  
  
  // 出力
  for(int i = 0; i < grids.size(); ++i)
  {
    for(int j = 0; j < grids.at(i).size(); ++j)
    {
      cout << grids.at(i).at(j);
    }
    cout << endl;
  }
  
  return 0;
}

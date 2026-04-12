#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  vector<vector<char>> data(H, vector<char>(W));
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      cin >> data.at(i).at(j);
    }
  }
  
  vector<int> row;
  vector<int> col;
  
  for (int i = 0; i < H; i++) {
    bool flag = true;
    for (int j = 0; j < W; j++)
    {
      if( data.at(i).at(j) == '#' )
      {
        flag = false;
      }
    }
    if (flag == true)
    {
      row.push_back(i);
    }
  }  

  for (int i = 0; i < W; i++) {
    bool flag = true;
    for (int j = 0; j < H; j++)
    {
      if( data.at(j).at(i) == '#' )
      {
        flag = false;
      }
    }
    if (flag == true)
    {
      col.push_back(i);
    }
  }  
  
  for (int i = 0; i < H; i++)
  {
    bool flag = false;  
    for (int x: row)
    {
      if(x == i)
      {
        flag = true;
        break;
      }
    }
    if (flag == true)
    {
      continue;
    }
    
    for (int j = 0; j < W; j++)
    {
      flag = false;
      for (int x: col)
      {
        if(x == j)
        {
          flag = true;
          break;
        }
      }
      if(flag == false)
      {
      	cout << data.at(i).at(j);
      }
    }
    cout << endl;
  }
  
  
}

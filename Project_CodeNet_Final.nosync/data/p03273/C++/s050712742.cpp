#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> a(H, vector<char>(W));
  for(int i = 0; i < H; i++)
  {
    for(int j = 0; j < W; j++)
    {
      cin >> a.at(i).at(j);
    }
  }
  vector<int> A(H, 0), B(W, 0);
  for(int i = 0; i < H; i++)
  {
      int cnt = 0;
    for(int j = 0; j < W; j++)
    {
      if(a.at(i).at(j) == '#')
        A.at(i) = 1;
      else
        continue;
    }
  }

  for(int i = 0; i < W; i++)
  {
    int cnt = 0;
    for(int j = 0; j < H; j++)
    {
      if(a.at(j).at(i) == '#')
        B.at(i) = 1;
      else
        continue;
    }
  }
  
  for(int i = 0; i < H; i++)
  {
    if(A.at(i) != 0)
    {
      for(int j = 0; j < W; j++)
      {
        if(B.at(j) != 0)
        {
          cout << a.at(i).at(j);
        }
      }
      cout << endl;
    }
    else
      continue;
  }
}

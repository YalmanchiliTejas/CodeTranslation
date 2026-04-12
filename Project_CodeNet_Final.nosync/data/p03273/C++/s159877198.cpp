#include<bits/stdc++.h>
using namespace std;

int main()
{
  int h, w;
  cin >> h >> w;
  vector<vector<char>> a(h, vector<char>(w));
  int i, j;
  for(i = 0; i < h; i++)
  {
    for(j = 0; j < w; j++)
    {
      cin >> a.at(i).at(j);
    }
  }
  int count;
  vector<bool> checkh(h, false);
  vector<bool> checkw(w, false);
  for(i = 0; i < h; i++)
  {
    count = 0;
    for(j = 0; j < w; j++)
    {
      if(a.at(i).at(j) == '#') count++;
    }
    if(count == 0) checkh.at(i) = true;
  }
  for(i = 0; i < w; i++)
  {
    count = 0;
    for(j = 0; j < h; j++)
    {
      if(a.at(j).at(i) == '#') count++;
    }
    if(count == 0) checkw.at(i) = true;
  }
  for(i = 0; i < h; i++)
  {
    for(j = 0; j < w; j++)
    {
      if(checkh.at(i) == false && checkw.at(j) == false)
      {
        cout << a.at(i).at(j);
      }
    }
    if(checkh.at(i) ==false) cout << endl;
  }
}
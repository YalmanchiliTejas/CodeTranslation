#include <cstdlib>
#include <iostream>
#include <typeinfo>
#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int h, w;
  int ci = 0, cj = 0;
  cin >> h >> w;
  vector<vector<char>> a(h, vector<char>(w));
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      cin >> a.at(i).at(j);
    }
  }

  //行ごとに
  for (int i = 0; i < h; i++)
  {
    bool b = true;
    for (int j = 0; j < w; j++)
    {
      if (a.at(i).at(j) == '#')
      {
        b = false;
        break;
      }
    }
    if (b)
    {
      for (int di = i; di < h; di++)
      {
        for (int j = 0; j < w; j++)
        {
          if (di != h - 1)
          {
            a.at(di).at(j) = a.at(di + 1).at(j);
          }
          else
          {
            a.at(di).at(j) = 'f';
          }
        }
      }
      ci++;
      i--;
    }
    if (ci == h - 1)
    {
      break;
    }
  }
  //列ごとに
  for (int j = 0; j < w; j++)
  {
    bool b = true;
    for (int i = 0; i < h; i++)
    {
      if (a.at(i).at(j) == '#')
      {
        b = false;
        break;
      }
    }
    if (b)
    {
      for (int dj = j; dj < w; dj++)
      {
        for (int i = 0; i < h; i++)
        {
          if (dj != w - 1)
          {
            a.at(i).at(dj) = a.at(i).at(dj + 1);
          }
          else
          {
            a.at(i).at(dj) = 'f';
          }
        }
      }
      cj++;
      j--;
    }
    if (cj == w - 1)
    {
      break;
    }
  }
  //output
  bool f = true;
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      if(a.at(i).at(j)=='f'){
        if(j==0){
          f = false;
          break;
        }else{
          break;
        }
      }else{
        cout << a.at(i).at(j);
      }
    }
    if (!f)
      break;
    cout << endl;
  }
  return 0;
}
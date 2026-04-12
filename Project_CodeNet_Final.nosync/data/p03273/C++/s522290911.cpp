#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <string>
#include <typeinfo>
#include <vector>
//#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<bool>> vvb;
typedef vector<vector<int>> vvi;

#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)

int main()
{
  int h, w;
  cin >> h >> w;
  vector<vector<char>> a(h, vector<char>(w));
  vb bh(h, false);
  vb bw(w, false);
  rep(i, h)
  {
    rep(j, w)
    {
      cin >> a.at(i).at(j);
      if (a.at(i).at(j) == '#')
      {
        bh.at(i) = true;
        bw.at(j) = true;
      }
    }
  }
  rep(i, h)
  {
    rep(j, w)
    {
      if (bh.at(i) && bw.at(j))
      {
        cout << a.at(i).at(j);
      }
    }
    if(bh.at(i)){
      cout << endl;
    }
  }

  return 0;
}
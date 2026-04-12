#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <map>
#include <cmath>
#include <string>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define REP(i,a,b)for(int i=(int)(a);(i)<(int)(b);i++)
typedef long long ll;


ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll c, ll d) { return c / gcd(c, d) * d; }

int main() {
  int h, w;
  cin >> h >> w;

  /* if input is ".", it is judged as white. */
  bool white[h][w] = { false };
  bool row_check[h] = { false };
  bool column_check[w] = { false };
  vector<vector<char>> grids(h, vector<char>(w));

  /* input and judge row. */
  rep (i, h) {
      int count = 0;
      rep (j, w) {
          cin >> grids[i][j];
          if (grids[i][j] == '.') 
          {
              white[i][j] = true; count++;
          }
      }
      if (count == w)
      {
          row_check[i] = true;
      }
  }

  /* judge column. */
  rep (i, w) {
      int count = 0;
      rep (j, h) {
          if (grids[j][i] == '.') 
          {
              white[j][i] = true; count++;
          }
      }
      if (count == h)
      {
          column_check[i] = true;
      }
  }
  for (int i = 0; i < h; i++)
  {
      for (int j = 0; j < w; j++)
      {
          if (column_check[j] != true && row_check[i] != true)
          {
            cout << grids.at(i).at(j);
          }
          if (row_check[i] != true && j == w-1) cout << endl;
      }
  }
  //for(vector<char> grid : grids)
  //{
  //    cout << grid << endl;
  //}
  return 0;
}
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = pow(10, 9) + 7;
//const int MOD = 998244353;
//const int MOD = ;
int mod(int A, int M) {return (A % M + M) % M;}
const int INF = 1LL << 60;
const string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string abc = "abcdefghijklmnopqrstuvwxyz";
template <class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template <class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
int divCeil(int A, int B) {return (A + (B - 1)) / B;}

signed main()
{
  int H, W;
  cin >> H >> W;
  vector<string> a(H);
  for (int i = 0; i < H; i++)
  {
    cin >> a.at(i);
  }
  
  vector<vector<bool>> save(H, vector<bool>(W, true));

  for (int i = 0; i < H; i++)
  {
    bool ok = false;
    for (int j = 0; j < W; j++)
    {
      if (a.at(i).at(j) == '#')
      {
        ok = true;
        break;
      }
    }
    if (!ok)
    {
      for (int k = 0; k < W; k++)
      {
        save.at(i).at(k) = false;
      }
    }
  }

  for (int j = 0; j < W; j++)
  {
    bool ok = false;
    for (int i = 0; i < H; i++)
    {
      if (a.at(i).at(j) == '#')
      {
        ok = true;
        break;
      }
    }
    if (!ok)
    {
      for (int k = 0; k < H; k++)
      {
        save.at(k).at(j) = false;
      }
    }
  }
  
  for (int i = 0; i < H; i++)
  {
    bool ok = false;
    for (int j = 0; j < W; j++)
    {
      if (save.at(i).at(j))
      {
        cout << a.at(i).at(j);
        ok = true;
      }
    }
    if (ok) cout << endl;
  }
}
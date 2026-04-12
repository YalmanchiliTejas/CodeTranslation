#include <bits/stdc++.h>
using namespace std;
const long long mod = pow(10, 9) + 7;
const long long MOD = 998244353;
const long long INF = 1LL << 60;
const int inf = pow(10, 9) + 7;
template <class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template <class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
int divCeil(int A, int B) {return (A + (B - 1)) / B;}
long long divCeil(long long A, int B) {return (A + (B - 1)) / B;}
long long divCeil(int A, long long B) {return (A + (B - 1)) / B;}
long long divCeil(long long A, long long B) {return (A + (B - 1)) / B;}

int main()
{
  int H, W;
  cin >> H >> W;
  vector<int> M(H, 0), m(H, 0);
  for (int i = 0; i < H; i++)
  {
    string S;
    cin >> S;
    bool flg = false;
    for (int j = 0; j < W; j++)
    {
      if (S.at(j) == '#')
      {
        if (!flg)
        {
          m.at(i) = j;
          flg = true;
        }
        M.at(i) = j;
      }
    }
  }
  
  string ans = "Possible";
  for (int i = 1; i < H; i++)
  {
    if (M.at(i - 1) != m.at(i))
    {
      ans = "Impossible";
      break;
    }
  }
  
  cout << ans << endl;
}
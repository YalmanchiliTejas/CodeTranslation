#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int k, size;
int num[1001];
int64_t dp[1001][2][4];
// dp[ 決めた桁数 ][ 未満フラグ ][ 0以外(1-9)==K個 ] :[size][0-1][K] 総数
// 未満フラグ == 0 : ちょうどその数の時。今回は以下なので含む、未満の時は含まない。

bool add(int i, bool smaller, int current_k, int x)
{
  int64_t now = dp[i][smaller][current_k];

  if (x < num[i])
    smaller = true;

  if (x != 0)
    current_k++;

  if (current_k > k)
    return false;

  dp[i + 1][smaller][current_k] += now;
  return true;
}

int main()
{
  string s;
  cin >> s >> k;
  size = s.size();
  
  // cout << s << endl;
  // cout << size << endl;

  rep(i, size)
      num[i] = s[i] - '0';

  //初期条件
  dp[0][0][0] = 1;

  rep(i, size)
  {
    rep(smaller, 2)
    {
      rep(kk, k + 1)
      {
        int max;
        if (smaller)
          max = 9;
        else
          max = num[i];

        rep(x, max + 1)
        {
          add(i, smaller, kk, x);
        }
      }
    }
  }
  // rep(i, size + 1)
  // {
  //   rep(smaller, 2)
  //   {
  //     rep(kk, k + 1)
  //     {
  //       cout << "i" << i << "smaller" << smaller << "kk" << kk << " = " << dp[i][smaller][kk] << endl;
  //     }
  //   }
  // }
  int64_t cnt = dp[size][0][k] + dp[size][1][k];
  cout << cnt << endl;
}
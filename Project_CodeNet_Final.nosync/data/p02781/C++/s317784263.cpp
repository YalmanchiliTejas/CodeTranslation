#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int k, size;
// 0-9
int num[101];
// dp[ 決めた桁数 ][ 未満フラグ ][ 0以外(1-9)==K個 ] :[size][0-1][K] 総数
// 未満フラグ == 0 : ちょうどその数の時。今回は以下なので含む、未満の時は含まない。
int64_t dp[101][2][4];

void add(int i, bool smaller, int current_k, int x)
{
  int64_t now_digit = dp[i][smaller][current_k];

  if (x < num[i])
    smaller = true;

  if (x != 0)
    current_k++;

  // next digit
  i++;

  dp[i][smaller][current_k] += now_digit;
}

void loop(int i, bool smaller, int current_k)
{
  int64_t cnt = dp[i][smaller][current_k];
  if (cnt == 0)
    return;

  int max;

  if (current_k == k)
    max = 0;
  else if (smaller)
    max = 9;
  else
    max = num[i];

  rep(x, max + 1)
      add(i, smaller, current_k, x);
}

int main()
{
  string s;
  cin >> s >> k;
  size = s.size();

  rep(i, size)
      num[i] = s[i] - '0';

  dp[0][0][0] = 1;
  rep(i, size)
      rep(smaller, 2)
          rep(j, k + 1)
              loop(i, smaller, j);
  int64_t cnt = dp[size][0][k] + dp[size][1][k];
  cout << cnt << endl;
}
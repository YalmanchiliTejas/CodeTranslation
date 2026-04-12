#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n;
ll dp[200001][2][11];
ll OO = 2e15;
ll N = -2e16;
vector<int> arr;

ll solve(int in, int lst, int dif){
  int left = (in + dif) / 2;
  int taken = (in - dif) / 2;
  if(left + taken != in || dif < -1 || dif > 8)
    return -OO;

  if(in == n)
    return taken == n/2 ? 0 : -OO;

  ll& res = dp[in][lst][dif + 1];
  if(res != N)
    return res;
  res = 0;

  if(lst)
    res = solve(in + 1, 0, dif + 1);
  else
    res = max(
      solve(in + 1, 0, dif + 1),
      solve(in + 1, 1, dif - 1) + arr[in]
    );
  return res;
}
int main()
{
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  for(int i = 0;i < 200001;i++)
    for(int j = 0;j < 2;j++)
      for(int k = 0;k < 11;k++)
        dp[i][j][k] = N;
  cin >> n;
  arr.resize(n);
  for(auto& el : arr)
    cin >> el;
  cout << solve(0, 0, 0);
  return 0;
}

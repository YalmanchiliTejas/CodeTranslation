#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int N, M;
vector< int > g[8];
int64 dp[1 << 8];

int64 rec(int idx, int bit)
{
  if(bit == (1 << N) - 1) return (1);
  if(~dp[bit]) return (dp[bit]);
  int64 ret = 0;
  for(auto &to : g[idx]) {
    if((bit >> to) & 1) continue;
    ret += rec(to, bit | (1 << to));
  }
  return (ret);
}

int main()
{

  cin >> N >> M;
  for(int i = 0; i < M; i++) {
    int A, B;
    cin >> A >> B;
    g[--A].push_back(--B);
    g[B].push_back(A);
  }
  memset(dp, -1, sizeof(dp));
  cout << rec(0, 1) << endl;
}
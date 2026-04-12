#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
static const int INF (1<<30);

int N;
long long X;
long long ans[51], cnt[51];

long long dfs(int id, long long rem) {
  if (rem == 1) {
    if (id == 0) return 1;
    else return 0;
  } 
  else if (rem >= 2 && rem <= cnt[id-1]+1) {
    return dfs(id-1, rem-1);
  } 
  else if (rem == cnt[id-1]+2) {
    return ans[id-1] + 1;
  } 
  else if (rem == cnt[id]) {
    return 2*ans[id-1] + 1;
  } 
  else {
    return dfs(id-1, rem-cnt[id-1]-2) + 1 + ans[id-1];
  }
}

int main() {
  cin >> N >> X;

  ans[0] = 1;
  cnt[0] = 1;

  long long res;
  for (int i = 1; i <= N; i++) {
    cnt[i] = 2 * cnt[i-1] + 3;
    ans[i] = 2 * ans[i-1] + 1;
    /*if (cnt[i] < X) {
      ans[i] = 2 * ans[i-1] + 1;
    } else {
      res = dfs(i, X);
      break;
    }*/
  }


  res = dfs(N, X);

  cout << res << endl;

  return 0;
}
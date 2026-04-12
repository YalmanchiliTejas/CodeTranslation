#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

double getTime() {
  return clock() / (double) CLOCKS_PER_SEC;
}

void read() {};

template<typename T, typename... Args>
void read(T& a, Args&... args) {
  cin >> a;
  read(args...);
}

void print() {};

template <typename T, typename... Args>
void print(T a, Args... args) {
  cout << a << " \n"[sizeof...(args) == 0];
  print(args...);
}

const ll MOD = 998244353;

int main() {
  int n, s; read(n, s);
  vector <ll> dp(s + 1, 0);
  ll sum = 0;
  for(int i = 0; i < n; i++) {
    int x; read(x);
    for(int j = s; j >= 0; j--) {
      if(j - x < 0) continue;
      dp[j] = (dp[j] + dp[j - x]) % MOD;
    }
    if(x <= s) dp[x] = (dp[x] + i + 1) % MOD;
    sum = (sum + dp[s]) % MOD;
  }
  print(sum);
}
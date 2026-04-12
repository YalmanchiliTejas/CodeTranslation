#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
constexpr ll INF = (1LL << 55);

int main(){ 
  int n;
  ll x;
  cin >> n >> x;

  auto dfs = [&](auto& f, int now, ll k)->ll{
    if (!now) return 1;
    ll len = (1LL << (now + 1)) - 3;
    ll num = (1LL << now) - 1;
    if (k == 1) return 0;
    else if (k <= len + 1) return f(f, now - 1, k - 1);
    else if (k == len + 2) return num + 1;
    else if (k <= (len + 1) * 2) return num + 1 + f(f, now-1, k - len - 2);
    return num * 2 + 1;
  };

  cout << dfs(dfs, n, x) << endl;
  return 0;  
} 
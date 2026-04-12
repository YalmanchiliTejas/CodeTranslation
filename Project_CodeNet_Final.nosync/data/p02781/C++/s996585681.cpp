#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl

const int maxn = 110;


int n;
string s;
int k;

ll cache[maxn][5][3][3];

ll dfs(int i, int nonz, bool lower, bool f) {
  if (nonz > k) return 0;
  if (i == n) {
    return (nonz == k);
  } else {
    if (cache[i][nonz][lower][f] != -1) {
      return cache[i][nonz][lower][f];
    }
    ll res = 0;
    int dig = s[i]-'0';
    for (int d=(f ? 1: 0); d<=(lower ? 9 : dig); d++) {
      res += dfs(i + 1, nonz + (d>0), lower || (d<dig), false);
    }
    return cache[i][nonz][lower][f] = res;
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

  memset(cache, -1, sizeof cache);
  
  cin>>s>>k;
  n = s.length();
  ll ans = 0;

  for (int i=0; i<n; i++) {
    ans += dfs(i, 0, i>0, true);
  }

  cout<<ans<<endl;
  return 0;
}

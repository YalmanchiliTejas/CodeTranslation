#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define All(x) (x).begin(),(x).end()
typedef long long ll;
using Graph = vector<vector<int>>;
const int INF = 1000000007;
int main(){
  int n;
  cin >> n;
  vector<ll>v(n);
  rep(i,n)cin >> v[i];
  sort(All(v));
  ll ans = v[n - 1] - v[0];
  for(int i = 0,j = n - 2;i + 1 < j; ++i,--j)ans += v[j] - v[i];
  for(int i = 1,j = n - 1;i + 1 < j;++i,--j)ans += v[j] - v[i];
  if(n & 1)ans += max(v[n / 2 + 1] - v[n / 2],v[n / 2] - v[n / 2 - 1]);
  cout << ans << endl;
  return 0;
}

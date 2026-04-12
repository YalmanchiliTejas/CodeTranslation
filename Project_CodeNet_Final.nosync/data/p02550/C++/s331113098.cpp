#include <iostream>
#include <vector>
using namespace std;
using ll=long long;

int main() {
  ll n, x, m;
  cin >> n >> x >> m;
  vector<int> id(m, -1); // iが何回目に登場したか
  vector<int> list;
  
  // 周期を得るまで回す
  ll x1 = x;
  int len = 0;
  ll total = 0;
  while (id[x1] == -1) {
    list.push_back(x1);
    id[x1] = len;
    len++;
    total += x1;
    x1 = x1 * x1 % m;
  }
  int c = len - id[x1]; // 周期のノード数
  ll c_total = 0; // 周期の合計点数 
  for (int i=id[x1]; i<len; i++) c_total += list[i];
  
  ll ans = 0;
  ll x2 = x;
  if (n <= len) {
    for (int i=1; i<=n;i++) {
      ans += x2;
      x2 = x2*x2%m;
    }
  } else {
    // 周期を使える時
    ans += total;
    n -= len;  //残り回数
    ans += (n / c) * c_total;
    n %= c;
    for (int i=0; i<n; i++) ans += list[ id[x1] + i];
  }
  
  cout << ans;
}
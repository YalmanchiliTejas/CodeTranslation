#ifdef ConanYu
#include "local.hpp"
#else
#pragma GCC optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void Main();
#define debug(...) do { } while(0)
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  Main();
}
#endif

void Main() {
  int n, m; cin >> n >> m;
  if(n == m) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}
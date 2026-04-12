/**
 * @author yuzining
 * @date 2020/08/02 20:00
 */

#ifdef local
#include "D:\vscode\acm\local.hpp"
#else
#include<bits/stdc++.h>
using namespace std;
#define debug(...) do { } while(false)
void Main();
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  Main();
  return 0;
}
#endif

void Main() {
  int n; cin >> n;
  cout << (n >= 30 ? "Yes\n" : "No\n");
}
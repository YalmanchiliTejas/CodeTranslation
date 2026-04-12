#ifdef ConanYu
#include "local.hpp"
#else
#pragma GCC optimize("-O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void Main();
#define debug(...) do { } while (false)
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  Main(); return 0;
}
#endif

void Main() {
  string s; cin >> s;
  bool a = false, b = false;
  for(int i = 0; i < 3; i++) {
    if(s[i] == 'A') a = true;
    else b = true;
  }
  cout << (a && b ? "Yes\n" : "No\n");
}
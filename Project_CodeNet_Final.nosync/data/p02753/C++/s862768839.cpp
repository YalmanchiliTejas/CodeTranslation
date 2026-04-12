#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rng(i, a, b) for(int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define urng(i, a, b) for(int i = int(b) - 1; i >= int(a); i--)
#define urep(i, b) urng(i, 0, b)
#define pb push_back
#define eb emplace_back
#define F first
#define S second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed

int main() {
  int n, a, b, ans = 0;
  string s;
  cin >> s;
  //vector<int> v(n), c(n);
  //if(1) {}
  //
  //for(int i = 0; i < n; i++){}
  cout << ((s == "AAA" || s == "BBB")? "No" : "Yes") << endl;
}
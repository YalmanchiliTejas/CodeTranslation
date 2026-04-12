#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for (int i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
typedef long long ll;

int main()
{
  string a, b, c;
  cin >> a >> b >> c;
  int bc = stoi(b + c);
  cout << ((bc % 4 == 0) ? "YES" : "NO") << endl;
}
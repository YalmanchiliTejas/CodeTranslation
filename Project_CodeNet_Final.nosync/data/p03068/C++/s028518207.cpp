#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define rep(j, n) for(int j = 0; j < (n); j++)
typedef long long ll;
typedef long double ld;
using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, k;
  string s;
  cin >> n >> s >> k;
  --k;
  for (int i = 0; i < n; i++) {
    if (s[i] != s[k]) cout << '*';
    else cout << s[i];
  }
  cout << "\n";

  return 0;
}
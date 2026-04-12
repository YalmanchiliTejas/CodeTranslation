#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define RFOR(i, a, b) for(int i=(a); i>=(b); i--)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) RFOR(i, n, 0)
#define dump(x)  cout << #x << " = " << (x) << endl;

typedef long long ll;
typedef pair<int, int> ii;
const ll INF = 1e18;
const int inf = 1e8;


void solve()
{
  string c;
  cin >> c;
  if (c=="a"||c=="e"||c=="i"||c=="o"||c=="u") cout << "vowel" << endl;
  else cout << "consonant" << endl;
}

int main()
{
  solve();
  return 0;
}

#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, n, m) for (int i = n; i < m; i++)
#define ll long long int

using namespace std;

int main()
{
  int n,k;
  string s;

  cin >> n;
  cin >> s;
  cin >> k;
  k--;

  REP(i,n) {
    if(s[i] != s[k]) {
      s[i] = '*';
    }
  }

  cout << s << endl;
}


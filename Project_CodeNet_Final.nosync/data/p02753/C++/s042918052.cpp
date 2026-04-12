#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  string s;
  cin >> s;
  string ans = "No";
  rep(i, s.size() - 1)
    if (s[i] != s[i+1])
    {
        ans = "Yes";
        break;
    }
  cout << ans << endl;
}
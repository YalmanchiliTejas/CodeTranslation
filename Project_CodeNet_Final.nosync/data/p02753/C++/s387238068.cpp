#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()
using namespace std;
using llong = long long;
using P = pair<int, int>;
const int inf = 1 << 20;
const int mod = 1e9 + 7;

int main() {
   string s;
   cin >> s;
   if(s[0] != s[1])
      cout << "Yes" << endl;
   else if (s[1] != s[2]) cout << "Yes" << endl;
   else if (s[0] != s[2])
      cout << "Yes" << endl;
   else cout << "No" << endl;
   return 0;
}
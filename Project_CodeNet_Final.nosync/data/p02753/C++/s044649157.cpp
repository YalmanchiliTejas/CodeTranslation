#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define INF 1e8
typedef long long int ll;
const double PI = acos(-1);

using Graph = vector<vector<int>>;
int main() {
  string s;
  cin >> s;
  if (s[0] == s[1] && s[1] == s[2] && s[2] == s[0])
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
}
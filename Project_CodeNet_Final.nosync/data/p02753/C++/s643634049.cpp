#include <bits/stdc++.h>
using namespace std;
#define SORT(a) sort((a).begin(), (a).end())
#define RSORT(a) reverse((a).begin(), (a).end())
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
const long long INF = 1LL << 60;
// const int INF=1010101010;
using Graph = vector<vector<int>>;

int main() {
  string s;
  cin >> s;
  bool a = false;
  bool b = false;
  for (int i = 0; i < 3; i++) {
    if (s[i] == 'A') a = true;
    if (s[i] == 'B') b = true;
  }
  if (a && b)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
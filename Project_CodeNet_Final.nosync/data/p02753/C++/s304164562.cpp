#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
int main() {
  string s;
  cin >> s;
  int ok1 = 0, ok2 = 0;
  for (char x : s)
    if (x == 'A')
      ok1 = 1;
    else
      ok2 = 1;
  if (ok1 && ok2)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
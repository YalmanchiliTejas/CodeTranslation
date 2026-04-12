#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define contains(v, t) (find(v.begin(), v.end(), t) != v.end())
#define MOD 1000000007
typedef long long ll;
typedef unsigned long long ull;

int main() {
  int x;
  cin >> x;
  if (x == 7 || x == 5 || x == 3) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}
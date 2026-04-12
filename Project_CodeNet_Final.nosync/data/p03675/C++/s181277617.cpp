#include <bits/stdc++.h>

#define FOR(i, a, b)  for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a); i >= (b); i--)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << "\n"
#define _ << " _ " <<
#define ll long long
#define pil pair <int, ll>
#define pii pair <int, int>

using namespace std;

deque <int> b;

int main() {
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  REP(i, n) {
    int a;
    cin >> a;
    if (i % 2 == 0) b.push_back(a);
    else            b.push_front(a);
  }
  while (!b.empty()) {
    if (n % 2 == 1) {
      cout << b.back() << " ";
      b.pop_back();
    } else {
      cout << b.front() << " ";
      b.pop_front();
    }
  }

  return 0;
}


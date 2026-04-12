#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> point;

deque<int> dq;

const int MAXN = 2e5 + 5;

int a[MAXN];

int main() {
  int n; cin >> n;

  REP(i, n) {
    if((i % 2 + n % 2) % 2) {
      dq.push_front(i);
    }
    else {
      dq.push_back(i);
    }
  }

  REP(i, n) {
    cin >> a[i];
  }

  REP(i, n) {
    cout << a[dq[i]] << " ";
  }
}

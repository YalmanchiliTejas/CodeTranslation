#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++i < n; )
#define sz(v) ((int)v.size())

deque<int> qu;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  bool o = false;
  while (n--) {
    int num; cin >> num;
    if (o) qu.push_back(num);
    else qu.push_front(num);
    o = !o;
  }

  while (sz(qu)) {
    if (!o) {
      cout << qu.back() << ' ';
      qu.pop_back();
    } else {
      cout << qu.front() << ' ';
      qu.pop_front();
    }

  }

  return 0;
}

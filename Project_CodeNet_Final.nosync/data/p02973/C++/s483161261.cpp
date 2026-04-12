#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
using namespace std;
typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  // vector<int> b = {50, 40, 30, 20, 10};
  // cout << *(lower_bound(b.rbegin(), b.rend(), 1)) << endl;
  // return 0;

  int N; cin >> N;
  deque<int> a;

  rep(i, N) {
    int A; cin >> A;

    int p = lower_bound(a.begin(), a.end(), A) - a.begin();
    if(p == 0) {
      a.push_front(A);
    } else {
      a[p-1] = A;
    }
  }

  cout << a.size() << endl;
}


// 1,2

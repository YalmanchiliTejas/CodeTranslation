#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main() {
  int n;
  int a;
  deque<int> deq;
  cin>>n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (i & 1)
      deq.push_front(a);
    else
      deq.push_back(a);
  }
  if (n & 1) reverse(deq.begin(), deq.end());
  for (auto&& b : deq) {
    cout << b << " ";
  }
  cout << endl;

  return 0;
}

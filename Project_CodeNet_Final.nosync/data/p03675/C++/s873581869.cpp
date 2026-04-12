#include <bits/stdc++.h>
using namespace std;

#define int long long

main()
{
  int n;
  int a;
  deque < int > deq;

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a;
    if((n + i) % 2 == 1) {
      deq.push_front(a);
    } else {
      deq.push_back(a);
    }
  }

  while(!deq.empty()) {
    cout << deq.front();
    deq.pop_front();
    if(!deq.empty()) cout << " ";
  }
  cout << endl;
  return (0);
}

#include<bits/stdc++.h>
using namespace std;
int main() {
  deque<int>dq;
  int n;
  int a;
  cin >> n;
  for(int i = 0; i < n; ++i) {
    cin >> a;
    if(i % 2) dq.push_front(a);
    else dq.push_back(a);
  }
  
  if(n % 2) reverse(dq.begin(), dq.end());
  cout << dq[0];
  for(int i = 1; i < dq.size(); ++i) cout << " " << dq[i];
  cout << endl;
  return 0;
}

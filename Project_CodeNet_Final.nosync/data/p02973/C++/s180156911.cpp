#include<bits/stdc++.h>
using namespace std;

int N;
int A[100000];

signed main() {
  cin >> N;
  for(int i=0; i<N; i++) cin >> A[i];

  int color = 1;
  multiset<int> s;
  s.insert(A[0]);

  for(int i=1; i<N; i++) {
    int a = A[i];
    auto lb = s.lower_bound(a);
    if(lb == s.begin()) {
      s.insert(a);
      color++;
    }
    else {
      s.erase(prev(lb));
      s.insert(a);
    }
  }
  cout << color << endl;
}

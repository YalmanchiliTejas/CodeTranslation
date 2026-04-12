#include<bits/stdc++.h>
using namespace std;

int N;
int A[100000];

signed main() {
  cin >> N;
  for(int i=0; i<N; i++) cin >> A[i];

  int color = 1;
  set<pair<int,int>> s;
  s.insert(make_pair(A[0], 0));

  for(int i=1; i<N; i++) {
    int a = A[i];
    auto lb = s.lower_bound(make_pair(a,0));
    if(lb == s.end()) {
      auto rb = s.rbegin();
      int c = (*rb).second;
      s.erase(prev(s.end()));
      s.insert(make_pair(a, c));
    }
    else if(lb == s.begin()) {
      s.insert(make_pair(a, color));
      color++;
    }
    else {
      auto p = prev(lb);
      int c = (*p).second;
      s.erase(p);
      s.insert(make_pair(a, c));
    }
  }
  cout << color << endl;
}


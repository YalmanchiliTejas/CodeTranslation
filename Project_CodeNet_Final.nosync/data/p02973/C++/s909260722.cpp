#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
  int N; cin >> N;
  vector<int> a(N);
  for(int i = 0; i < N; i++) cin >> a[i];
  deque<int> deq;
  for(int i = 0; i < N; i++){
    int id = lower_bound(deq.begin(), deq.end(), a[i]) - deq.begin();
    if(id == 0) deq.push_front(a[i]);
    else deq[id - 1] = a[i];
  }
  cout << deq.size() << endl;
}
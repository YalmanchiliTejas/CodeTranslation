#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
typedef long long ll;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  deque<int> que;
  rep(i,n) {
    int p = lower_bound(que.begin(), que.end(), a[i]) - que.begin();
    if (p == 0) {
      que.push_front(a[i]);
    } else que[p-1] = a[i];
  }
  int res = que.size();
  cout << res << endl;
  return 0;
}
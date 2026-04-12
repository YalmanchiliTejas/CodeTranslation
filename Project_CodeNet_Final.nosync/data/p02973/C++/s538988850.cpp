#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  deque<int> dq;
  rep(i, n) {
    int p = lower_bound(dq.begin(), dq.end(), a[i]) - dq.begin();
    if (p == 0) {
      dq.push_front(a[i]);
    } else {
      dq[p - 1] = a[i];
    }
  }
  int ans = dq.size();
  cout << ans << endl;
  
}
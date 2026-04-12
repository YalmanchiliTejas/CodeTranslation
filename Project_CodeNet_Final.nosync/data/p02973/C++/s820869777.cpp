#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
static const int INF (1<<30);


template<class T> int latter(const vector<T> &v, T x) {
  return upper_bound(v.begin(), v.end(), x) - v.begin();
}
template<class T> int former(const vector<T> &v, T x) {
  return lower_bound(v.begin(), v.end(), x) - v.begin() - 1;
}


int main() {
  int N; cin >> N;
  vector<int> a(N+1);
  rep(i, N) cin >> a[i];
  a[N] = INF;



  vector<int> ans;
  ans.push_back(-INF);
  ans.push_back(-a[0]);
  for(int i = 1; i < N; i++) {
    int asize = ans.size();
    if (a[i] <= -ans[asize-1]) {
      ans.push_back(-a[i]);
      continue;
    }

    int nx = latter(ans, -a[i]);
    if (nx == 0) {
      ans[1] = -a[i];
    } else {
      ans[nx] = -a[i];
    }
  }

  cout << ans.size()-1 << endl;



  return 0;
}
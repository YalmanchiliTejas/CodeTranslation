#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

#define REP(i,n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef	pair<int, int> pint;
int main() {
  int N; cin>>N;
  vector<pint> data(N);
  REP(i,N) {
    int	a; cin>>a;
    data[i] = make_pair(a, i);
  }
  sort(data.begin(), data.end());
  vector<int> ans(N);
  REP(i,N/2) {
    ans[data[i].second] = data[N/2].first;
  }
  for(int i = N/2; i < N; i++) {
    ans[data[i].second] = data[N/2-1].first;
  }
  REP(i,N) {
    cout << ans[i] << endl;
  }
  return 0;
}

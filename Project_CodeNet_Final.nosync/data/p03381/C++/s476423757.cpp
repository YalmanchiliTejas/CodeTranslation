#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 1e9;

int main(){
  int n;
  const int max_n = 2 * 1e5;
  vector<pair<int,int>> x;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int t;
    cin >> t;
    x.push_back(make_pair(t, i));
  }

  sort(x.begin(), x.end());

  int mid_left = n / 2 - 1;
  int mid_right = n / 2;
  int ans[max_n + 1];

  for(int i = 0; i < n; i++){
    if(i <= mid_left) ans[x[i].second] = x[mid_right].first;
    else ans[x[i].second] = x[mid_left].first;
  }
  for(int i = 0; i < n; i++){
    cout << ans[i] << endl;
  }

  return 0;
}
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> key;

void solve() {
  int n;
  vector<int> v;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int t;
    cin >> t;
    v.push_back(t);
  }
  ll cand = 0;
  {
    sort(v.begin(), v.end());
    map<int, int> dp;
    for(int i = 1; i < n; i++) {
      int j = i-1;
      if(i%2) dp[i]++; else dp[i]--;
      if(j%2) dp[j]++; else dp[j]--;
    }
    vector<int> scale;
    for(int i = 0; i < n; i++) scale.push_back(dp[i]);
    sort(scale.begin(), scale.end());
    ll ret = 0;
    for(int i = 0; i < n; i++) ret += scale[i] * v[i];
    cand = max(cand, ret);
  }
  {
    sort(v.begin(), v.end());
    map<int, int> dp;
    for(int i = 1; i < n; i++) {
      int j = i-1;
      if(i%2==0) dp[i]++; else dp[i]--;
      if(j%2==0) dp[j]++; else dp[j]--;
    }
    vector<int> scale;
    for(int i = 0; i < n; i++) scale.push_back(dp[i]);
    sort(scale.begin(), scale.end());
    ll ret = 0;
    for(int i = 0; i < n; i++) ret += scale[i] * v[i];
    cand = max(cand, ret);
  }
  cout << cand << "\n";
}

void casesolve() {
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << " ";
    solve();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  // casesolve();
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

int vminn(vector<int> v) {
  sort(v.begin(), v.end());
  return v[0];
}

signed main() {
  string A = "abcdefghijklmnopqrstuvwxyz";
  
  int n; cin >> n;
  vector<vector<int>> a(26, vector<int>(n, 0));
  rep(i, n) {
    string s; cin >> s;
    for(char c : s) {
      a[(c-'a')][i]++;
    }
  }
  
  rep(i, 26) {
    rep(j, vminn(a[i])) cout << A[i];
  }
  cout << endl;

}

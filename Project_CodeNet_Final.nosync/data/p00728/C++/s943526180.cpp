#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define ALL(obj) (obj).begin(), (obj).end()

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  while(true) {
    int n;
    cin >> n;
    if(n == 0) break;
    vector<int> v;
    int a;
    rep(i, n) {
      cin >> a;
      v.push_back(a);
    }
    sort(ALL(v));

    int sum = 0;
    for(int i = 1; i < n - 1; i++) {
      sum += v[i];
    }
    sum = sum / (n - 2);
    cout << sum << endl;
  }

}


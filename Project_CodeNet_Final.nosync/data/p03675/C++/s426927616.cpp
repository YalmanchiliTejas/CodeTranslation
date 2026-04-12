#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define pb push_back
#define rep(i, a, n) for(int i = (a); i < (n); i++)
#define dep(i, a, n) for(int i = (a); i >= (n); i--)
#define MOD 1000000007

__attribute__((constructor))
void initial() {
  cin.tie(0);
  ios::sync_with_stdio(false);
}

int main() {
  int n, b;
  vector<int> ans;
  cin >> n;
  int a = n % 2 == 0 ? 1 : 0;
  rep(i, 0, n) {
    cin >> b;
    if(i % 2 == a) ans.insert(ans.begin(), b);
    else ans.pb(b);
  }
  rep(i, 0, n) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

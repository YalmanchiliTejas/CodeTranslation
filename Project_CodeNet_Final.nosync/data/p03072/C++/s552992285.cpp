#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int INF = 1001001001;

int main() {
  int n, ans = 0, tmp = 0;
  cin >> n;
  vector<int> h(n);
  rep(i,n) {
    cin>>h[i];
    if(h[i] >= tmp) {
      tmp = h[i];
      ans++;
    }
  }

  cout<<ans<<endl;


  return 0;
}
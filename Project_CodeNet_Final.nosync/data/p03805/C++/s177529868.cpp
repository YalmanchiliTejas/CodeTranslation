#include<bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int , int>;
  
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m; cin >> n >> m;
  int a[m], b[m]; rep(i, m) cin >> a[i] >> b[i];
  int num[n];
  rep(i, n) num[i] = i+1;
  
  int ans = 0;
  do {
    if(num[0] != 1) continue;
    
    int cnt = 0;
    rep(i, n-1) {
      rep(j, m) {
	if(((num[i] == a[j]) && (num[i+1] == b[j])) || ((num[i] == b[j]) && num[i+1] == a[j])) {
	  ++cnt;
	  break;
	}
      }
    }
    ans += (cnt==(n-1));
  } while(next_permutation(num, num+n));
  cout << ans;
}
      

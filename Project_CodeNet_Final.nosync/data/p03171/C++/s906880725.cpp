#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i <= (n); i++)
#define loop(i, r, n) for (int i = (r); i <= (n); i++)
using namespace std;

int main(){
  int n; cin >> n;
  vector<long> a(n); rep(i,n) cin >> a[i];
  vector<vector<long>> ans(n+1,vector<long>(n+1,0));
  loop(i,1,n) loop(left,0,n-i){
    int right = i + left;
    ans[left][right] = max(a[left]-ans[left+1][right], a[right-1]-ans[left][right-1]);
  }
  cout << ans[0][n] << endl;
}
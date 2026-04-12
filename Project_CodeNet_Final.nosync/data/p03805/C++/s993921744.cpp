#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < n; ++i)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//~ using P = pair<int, int>;

int main(){
  int n, m;
  cin >> n >> m;
  
  vector<int> a(m), b(m);
  rep(i, m)
    cin >> a[i] >> b[i];
    
  vector<int> o(n);
  rep(i, n) o[i] = i+1;
  
  int cnt, ans;
  ans=0;
  do
  {
    if (o[0]!=1) break;
    
    cnt = 0;
    rep(i, n-1){
      rep(j, m){
        if((a[j]==o[i] && b[j]==o[i+1]) ||
           (a[j]==o[i+1] && b[j]==o[i])) cnt++;
      }
    }
    
    if (cnt==n-1) ans++;
  } while (next_permutation(o.begin(), o.end()));
  
  cout << ans << endl;
  return 0;
}

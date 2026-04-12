#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using T = tuple<string,int,int>;

int main(){
  int n; cin >> n;
  vector<int> h(n);
  for(int i = 0; i < n; i++){
    cin >> h[i];
  }
  int mx = h[0];
  int ans = 1;
  for(int i = 1; i < n; i++){
    if(mx > h[i]) continue;
    ans++;
    mx = h[i];
  }
  cout << ans << endl;
  return 0;
}
#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(void){
  int n; cin >> n;
  int h[n]; rep(i,n) cin >> h[i];
  int max = h[0];
  int ans = 1;
  for(int i = 1; i < n; i++){
    if(max <= h[i]){
      ans++;
      max = h[i];
    }
  }
  cout << ans << endl;
  return 0;
}

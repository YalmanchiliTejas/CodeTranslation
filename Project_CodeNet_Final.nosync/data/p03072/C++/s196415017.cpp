#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int n; cin >> n;
  vector<int> vec(n);
  rep(i,n) cin >> vec[i];

  int ans = 1;
  int max = vec[0];

  for(int i = 1; i < n; i++){
    if(vec[i] >= max){
      max = vec[i];
      ans++;
    }
  }

  cout << ans << endl;
}

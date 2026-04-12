#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

int n;
int H[110];

int main(){
  cin >> n;
  rep(i, n) cin >> H[i];
  int max_h = H[0];
  int ans = 1;
  rep(i, n-1){
    if (H[i+1] >= max_h){
      max_h = H[i+1];
      ans ++;
    }
  }
  cout << ans << endl;
}

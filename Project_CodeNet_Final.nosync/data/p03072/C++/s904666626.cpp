#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
  int N; cin >> N;
  int cnt = 1;
  int H1; cin >> H1;
  
  int t = H1;
  rep(i,N-1) {
    int H; cin >> H;
    if(H>=t) cnt++;
    t = max(H,t);
  }
  
  cout << cnt << endl;
  return 0;
}

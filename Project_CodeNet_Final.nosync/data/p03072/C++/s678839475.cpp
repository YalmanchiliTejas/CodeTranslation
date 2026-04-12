#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  for (int i = 0; i < N; i++)
  {
    cin >> H[i];
  }
  
  int ans = 0;
  int MH = H[0];
  for (int i = 0; i < N; i++)
  {
    if (MH <= H[i]) {
      ans++;
      MH = H[i];
    }
  }
  cout << ans << endl;

  return 0;
}

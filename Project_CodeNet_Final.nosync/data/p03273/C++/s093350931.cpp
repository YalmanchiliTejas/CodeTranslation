#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }


int H,W;
string A[100];
bool IH[100], IW[100];

int main() {
  cin >> H >> W;
  rep(i,H) cin >> A[i];

  rep(i,H) rep(j,W) if(A[i][j] == '#') {
    IH[i] = true;
    IW[j] = true;
  }

  rep(i,H) rep(j,W) {
    if(IH[i] && IW[j]) cout << A[i][j];
    if(IH[i] && j == W - 1) cout << '\n';
  }
}

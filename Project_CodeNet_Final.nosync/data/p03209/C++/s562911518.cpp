#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const int INF = pow(2, 31) - 1;
#define ll long long
#define DEBUG(x) cout << "DEBUG>" << #x << ":" << x << endl;
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

vector<long long> bg_len(51);
vector<long long> pt(51);
long long f(int N, long long X) {
  if(N == 0) return 1;
  if(X == 1) {
    return 0;
  } else if(1 < X && X <= bg_len[N - 1] + 1) {
    return f(N - 1, X - 1);
  } else if(X == bg_len[N - 1] + 2) {
    return pt[N - 1] + 1;
  } else if(bg_len[N - 1] + 2 < X && X <= 2 * bg_len[N - 1] + 2) {
    return pt[N - 1] + 1 + f(N - 1, X - bg_len[N - 1] - 2);
  } else {
    return pt[N];
  }
}

int main() {
  int N;
  long long X;
  cin >> N >> X;
  bg_len[0] = 1;
  pt[0] = 1;
  REP(i, 50) {
    bg_len[i + 1] = 2 * bg_len[i] + 3;
    pt[i + 1] = 2 * pt[i] + 1;
  }
  long long ans = f(N, X);
  cout << ans << endl;
  return 0;
}

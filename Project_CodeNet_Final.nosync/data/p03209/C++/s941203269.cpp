#include<iostream>

#define rep2c(i, n) for (int i = 2; i <= (int)(n); i++)
typedef long long ll;

using namespace std;

ll N, X, S[55], P[55];

void foo() {
  S[1] = 5;
  P[1] = 3;
  rep2c(i, N) {
    S[i]=S[i-1]*2+3;
    P[i]=P[i-1]*2+1;
  }
  return;
}

ll bar(ll level, ll pos) {
  if(level==1) {
    if(pos==5) return pos-2;
    else return pos-1;
  }
  ll mid = S[level]/2+1;
  if(pos == S[level]) return P[level];
  else if(pos == 1)   return 0;
  else if(pos == mid) return P[level-1]+1;
  else if(pos < mid)  return bar(level-1, pos-1);
  else                return P[level-1]+1+bar(level-1, pos-mid);
}

void solve() {
  foo();
  cout << bar(N, X) << endl;
  return;
}

int main() {
  cin >> N >> X;
  solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string S;
ll N, K;

ll com(ll N, ll R) {
    if (R < 0 || R > N) return 0;
    if (R == 1) return N;
    else if (R == 2) return N * (N-1) / 2;
    else return N * (N-1) * (N-2) / 6;
}

ll ctoi(char c) {
  if (c == '0') return 0;
  if (c == '1') return 1;
  if (c == '2') return 2;
  if (c == '3') return 3;
  if (c == '4') return 4;
  if (c == '5') return 5;
  if (c == '6') return 6;
  if (c == '7') return 7;
  if (c == '8') return 8;
  if (c == '9') return 9;
}

ll pow(ll n, ll k) {
  ll p = 1;
  for (ll i = 0; i < k; i++) {
    p *= n;
  }
  return p;
}

//左からn桁目までが決定している状況で、決定してないD-n桁に0でない数字がk個含まれている場合の数
ll res(int i, int k, bool smaller) {
  if (i == N) {
    if (k == 0) return 1;
    else return 0;
  } else if (k == 0) {
    return 1;
  } else if (smaller) {
    return com(N-i, k) * pow(9, k);
  } else {
    if (S.at(i) == '0') {
      return res(i+1, k, false);
    } else {
      ll ans = res(i+1, k, true);
      ans += (ctoi(S.at(i)) - 1) * res(i+1, k-1, true);
      ans += res(i+1, k-1, false);
      return ans;
    }
    
  }
}


int main() {
  cin >> S;
  N = S.size();
  cin >> K;
  
  cout << res(0, K, false) << endl;
}
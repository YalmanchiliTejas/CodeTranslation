#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<ll> b(51);

ll calc(ll depth, ll pos) {
  // P
  if (depth == 0) return 1;
  
  // BPPPB
  // ^
  if (pos == 1) return 0;

  ll mid = b[depth] / 2 + 1;
  if (mid == pos) {
    // BPPPB
    //   ^
    return (b[depth-1] / 2 + 1) + 1;
  } else if (mid < pos) {
    // BPPPB
    //    ^
    return ((b[depth-1] / 2 + 1) + 1) + calc(depth-1, pos-(b[depth]/2+1));
  } 
  // BPPPB
  //  ^
  return calc(depth-1, pos-1);
}

int main() {
  ll n, x;
  cin >> n >> x;
  
  b[0] = 1;
  for (ll i = 1; i <= n; ++i) {
    b[i] = 2*b[i-1]+3;
  }

  cout << calc(n, x) << endl;
 
  return 0;
}
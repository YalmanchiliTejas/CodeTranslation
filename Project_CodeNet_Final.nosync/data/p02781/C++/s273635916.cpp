#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;
#define ll signed long long 

string N;
ll K;
ll len;

ll combination(ll n, ll k) {
  if (n < k) {
    return 0;
  }
  ll ans = 1;
  for (int i = 0; i < k; ++i) {
    ans *= n - i;
  }
  for (int i = 0; i < k; ++i) {
    ans /= i + 1;
  }
  return ans;
}

ll all9 (ll n, ll k) {
  return (combination(n, k) * pow(9ll, k));
}

ll func (ll depth, ll k) {
  if (k == 0) {
    return 1;
  }
  if (depth == len) {
    return 0;
  }
  ll ret = 0;
  int num = N[depth] - '0';
  if (num > 1) {
    ret += all9(len - depth - 1, k - 1) * (num - 1);
  }
  if (num > 0) {
    ret += func(depth + 1, k - 1);
  }
  if (num > 0) {
    ret += all9(len - depth - 1, k);
  } else {
    ret += func(depth + 1, k);
  }
  return (ret);
}

int main (){
  cin >> N >> K;
  len = N.size();
  cout << func(0, K) << endl;
  return 0;
}

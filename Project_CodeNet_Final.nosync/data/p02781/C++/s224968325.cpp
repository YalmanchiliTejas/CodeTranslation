#include <iostream>
#include <assert.h>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

int ndig_cnt(int dig, int k) {
  if (dig < k) return 0;
  else if (k == 0 && dig == 1) return 1;
  else if (k == 0) return 0;
  else if (k == 1) return 9;
  else if (k == 2) {
    int base = 9 * 9;
    int divident = (dig - 1); 
    return base * divident;
  } else {
    int base = 9 * 9 * 9;
    int divident = (dig - 1) * (dig - 2); 
    int divider = 2;
    return base * divident / divider;
  }
}

int ndig_cnt_accum(int nd, int k) {
  int sum = 0;
  for (int i = 1; i <= nd; i++) {
    sum += ndig_cnt(i, k);
  }
  return sum;
}


int rec(string& N, int idx, int nd, int k) {
  //cout << "rec called:" << idx << "," << nd << "," << k << endl; 
  if (nd < k) {
    return 0;
  } else if (nd == 1 && k != 0) {
    //cout << N[idx] << endl;
    return N[idx] -'0';
  } else if (k == 0) {
    return 1;
  }
  if (N[idx] == '0') {
    return rec(N, idx + 1, nd - 1, k);
  } else {
    int res = ndig_cnt_accum(nd - 1, k);
    //cout << "check2 :" << res << endl;
    res += (N[idx] - '1') * ndig_cnt_accum(nd - 1, k - 1);
    res += rec(N, idx + 1, nd - 1, k -1);
    return res;
  }
}

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  string N;
  cin >> N;
  int K;
  cin >> K;
  int nd = N.size(); 
  if (nd < K) {
    cout << 0 << endl;
    return 0;
  } else if (nd == 1) {
    cout << N[0] - '0' << endl;
    return 0;

  }

  //cnt_init(nd);
  int sum = ndig_cnt_accum(nd - 1, K);
  sum += (N[0] - '1') * ndig_cnt_accum(nd - 1, K - 1);
  //cout << "check1: " << sum << endl;
  sum += rec(N, 1, nd - 1, K - 1);
  cout << sum << endl;
  return 0;
}

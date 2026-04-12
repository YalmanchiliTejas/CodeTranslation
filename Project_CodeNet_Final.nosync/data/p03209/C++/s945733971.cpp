#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

long calc_putty(long n, long x, vector<long>& putty, vector<long>& size) {
  if (n<=0) return (x>0? 1 : 0);

  long res = 0;
  if (size[n] == x) res = putty[n];
  if (size[n-1]+1 < x) res =  putty[n-1]+1 + calc_putty(n-1,x-size[n-1]-2,putty,size);
  else res = calc_putty(n-1,x-1,putty,size);

  // cout << n << " " << x << " " << res << endl;
  return res;
}


int main() {
  long n,x;
  long ans = 0;
  cin >> n >> x;
  vector<long> putty(n+1);
  vector<long> size(n+1);

  putty[0] = 1;
  size[0] = 1;
  for (int i=1; i<=n; i++) {
    putty[i] = putty[i-1]*2 +1;
    size[i] = size[i-1]*2 +3;
  }

  ans = calc_putty(n,x,putty,size);
  cout << ans << endl;
}

/*
0 : 1 - 1
1 : 5 - 3
2 : 13 - 7
BPPPB
B(L1)P(L1)B
B(BPPPB)P(BPPPB)B
BBPPPBPBPPPBB
*/
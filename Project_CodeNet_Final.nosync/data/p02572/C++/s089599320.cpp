#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define MOD 1000000007;

int main(void)
{
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i=0; i < N;i++) cin >> A.at(i);
  if (N==1) {cout << A[0] << endl; return 0;}
  // cout << A[1] << endl;

  unsigned long ans = 0;
  unsigned long sum_l = 0;
  for(int i=0; i < N -1; i++)
  {
    sum_l = (sum_l + A[i]) % MOD;
    ans += (sum_l * A[i+1]) % MOD;
  }
  ans =  ans % MOD;
  cout << ans << endl;
  return 0;
}

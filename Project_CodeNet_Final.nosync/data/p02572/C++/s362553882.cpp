#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

using namespace std;
typedef long long ll;

int main() {
  int N;
  ll A[200005];
  cin >> N;
  for (int i=0; i < N; i++) cin >> A[i];
  ll out=0;
  ll su=0;
  for(int i=0; i < N; i++) {
      if (i>0) su = (su + A[i-1]) % (1000000007);
      out = (out+(A[i]*su)) % (1000000007);
  }
  cout << out << endl;
  return 0;
}

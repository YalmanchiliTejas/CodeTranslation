#include <iostream>
#include <iomanip>
#include <cstdio>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
#include <string>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector <int> H(N + 1, 0);
  vector <int> M(N + 1, 0);
  for (int i = 1; i <= N; i++) {
	  cin >> H[i];
	  M[i] = max(M[i - 1], H[i]);
	}
  int ans = 0;
  for (int i = 1; i <= N; i++) {
	  if (M[i] <= H[i]) {
		  ans++;
		}
	}
  cout << ans << endl;
  return 0;
}

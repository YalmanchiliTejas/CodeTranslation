#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <numeric>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <cfloat>
using namespace std;
long long A[200000];
long long cumsum_A[200000];
const long long MOD = 1000000007;
int main(){
  int N;
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> A[i];
  }

  cumsum_A[N - 1] = A[N - 1];
  for(int i = N - 2; i >= 0; i--){
    cumsum_A[i] = (A[i] + cumsum_A[i + 1]) % MOD;
  }

  long long ans = 0;
  for(int i = 0; i < N - 1; i++){
    long long tmp = (A[i] * cumsum_A[i + 1]) % MOD;
    ans = (ans + tmp) % MOD;
  }
  cout << ans << endl;
  return 0;
}

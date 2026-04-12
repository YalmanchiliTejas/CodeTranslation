#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <tuple>
#include <queue>
#include <bitset>
#include <map>
#include <unordered_map>
#include <tuple>
#include <utility>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <sys/time.h>

using namespace std;

void solve(long long N, vector<long long> s){
  long long k, x;
  long long a, b;
  long long ans = 0;
  for (long long c = 1; c <= N-2; c++) {
    k = 1;
    x = 0;
    map<int, int> used;
    while (k*c < N-1) {
      a = N-1-k*c;
      b = a - c;
      if (a < 1 || b >= a || b < 1 || used.find(k*c)!=used.end() || used.find(N-1-k*c)!=used.end() || k*c == N-1-k*c) {
        break;
      }
      x += s[k*c];
      x += s[N-1-k*c];
      used[k*c] = 1;
      used[N-1-k*c] = 1;
      ans = max(ans, x);
      k++;
    }
  }
  std::cout << ans << std::endl;
}

int main(){
  long long N;
  scanf("%lld",&N);
  vector<long long> s(N);
  for(int i = 0 ; i < N ; i++){
    scanf("%lld",&s[i]);
  }
  solve(N, s);
  return 0;
}

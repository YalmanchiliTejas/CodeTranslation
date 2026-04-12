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
using namespace std;
int main(){
  int N;
  int K;
  cin >> N >> K;

  if(K == 0){
    cout << (long long) N * (long long) N << endl;
    return 0;
  }
  long long ans = 0;
  for(int i = K + 1; i <= N; i++){
    ans += (long long) (N / i) * (long long) (i - K);
    if(N % i >= K){
      ans += (long long) (N % i - K + 1);
    }
  }
  cout << ans << endl;
  return 0;
}

#include <bits/stdc++.h>
#define INF 2e9
#define MOD 1000000007
#define MOD9 998244353
#define intMAX 51000;
#define PI 3.14159265359
using namespace std;
typedef long long llong;
typedef long double ldouble;

using Graph = vector<vector<int>>;

int main(){
  int N;
  cin >> N;
  llong sum = 0;
  vector<llong> A(N);
  for(int i=0; i<N; ++i){
    cin >> A[i];
    sum += A[i];
    sum %= MOD;
    if(sum < 0) sum += MOD;
  }
  llong ans = 0;
  for(int i=0; i<N-1; ++i){
    sum -= A[i];
    if(sum < 0) sum += MOD;
    ans += A[i] * sum;
    ans %= MOD;
    if(ans < 0) ans += MOD;
  }
  ans %= MOD;
  if(ans < 0) ans +- MOD;
  cout << ans << endl;
}
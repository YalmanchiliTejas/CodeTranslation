#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
  
  long long N,X,M;
  cin >> N >> X >> M;

  vector<int> num(M,0);
  
  int cnt = 1;
  int st = 0,en = 0;
  long long x = X;
  for(int i = 0;i < N;i++) {
    if(num[x] != 0) {
      st = num[x];
      en = cnt;
      break;
    }
    num[x] = cnt;
    cnt++;
    x = x*x % M;
  }
  

  int n = en-st;
  
  
  long long ans = 0;

  if(n == 0) {
    for(int i = 0;i < N;i++) {
      ans += X;
      X = X*X%M;
    }
    cout << ans << endl;
    return 0;
  }

  for(int i = 0;i < st-1;i++) {
    ans += X;
    X = X*X%M;
  }

  long long loop_sum = 0;
  long long rest = N-st+1;
  long long loop_num = rest / n;
  int r = rest % n;
  for(int i = 0;i < n;i++) {
    if(i < r) ans += x;
    loop_sum += x;
    x = x*x%M;
  }

  ans += loop_num*loop_sum;
  cout << ans << endl;
 

}

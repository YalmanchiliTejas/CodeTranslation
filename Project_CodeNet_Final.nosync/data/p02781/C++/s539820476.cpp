#define _USE_MATH_DEFINES
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
#include <cmath>
#include <numeric>
#include <iomanip>

using namespace std;
long long p[200000];
long long p_sums[200000];
long long combin(int n, int m){
  long long numerator = 1;
  for(int i = 0; i < m; i++){
    numerator *= (n - i);
  }
  long long denominator = 1;
  for(int i = 0; i < m; i++){
    denominator *= (i + 1);
  }
  return numerator / denominator;
}
long long power(int n, int m){
  long long ans = 1;
  for(int i = 0; i < m; i++){
    ans *= (long long) n;
  }
  return ans;
}
int main(void){
  string S;
  int K;
  cin >> S;
  cin >> K;
  int N = S.size();
  long long ans = 0;
  for(int i = K; i <= N - 1; i++){
    ans += power(9, K) * combin(i - 1, K - 1);
  }
  ans += (long long) (S[0] - '1') * power(9, K - 1) *  combin(N - 1, K - 1);
  if(K == 1){
    ans ++;
  } else if(K == 2){
    if(N >= 2){
      int first_non_zero = N;
      for(int i = 1; i < N; i++){
        if(S[i] != '0'){
          first_non_zero = i;
          break;
        }
      }
      if(first_non_zero < N){
        ans += (long long) (S[first_non_zero] - '0');
        ans += (N - first_non_zero - 1) * (long long) 9;
      }
    }
  } else {
    /*
    for(int i = 1; i < N - 1; i++){
      for(int j = i + 1; j < N; j++){
        ans += (long long) (S[i] - '0') * (long long) (S[j] - '0');
      }
    }
    */
    
    if(N >= 3){
      int first_non_zero = N;
      int second_non_zero = N;
      for(int i = 1; i < N; i++){
        if(S[i] != '0'){
          first_non_zero = i;
          for(int j = i + 1; j < N; j++){
            if(S[j] != '0'){
              second_non_zero = j;
              break;
            }
          }
          break;
        }
      }
      if(first_non_zero < N){
        ans += power(9, K - 1) * combin(N - first_non_zero - 1, K - 1);
        ans += (long long) (S[first_non_zero] - '1') * (N - first_non_zero - 1) * (long long) 9;
      }
      if(second_non_zero < N){
        ans += (long long) (S[second_non_zero] - '0') + (N - second_non_zero - 1) * (long long) 9;
      }
      /*
      for(int i = 1; i < N; i++){
        if(S[i] != 0){
          ans += power(9, K - 1) * combin(N - i - 1, K - 1);

        }
      }
      ans += power(9, K - 1) * combin(N - 2, K - 1);
      if(S[1] > '1'){
        ans += (long long) (S[1] - '1') * (N - 2) * (long long) 9;
      }
      ans += (long long) (S[2] - '0') + (N - 3) * (long long) 9; 
      */
    }
  }
  
  cout << ans << endl;
  return 0;
}

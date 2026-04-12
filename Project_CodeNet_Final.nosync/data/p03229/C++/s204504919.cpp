#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>

using namespace std;

const int nmax = 1e9 + 7;
typedef long long ll;

int main(){

  int N; cin >> N;
  vector <ll> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  sort(A.begin(), A.end());

  
  int start = 0, end = N - 1;
  ll now1 = A[start], now2 = A[end];
  ll ans = now2 - now1;

  for (int i = 0; i < N - 2; i++){
    ll num1 = abs(now1 - A[start + 1]);
    ll num2 = abs(now1 - A[end - 1]);
    ll num3 = abs(now2 - A[start + 1]);
    ll num4 = abs(now2 - A[end - 1]);

    ll M = max(max(num1, num2), max(num3, num4));
    ans += M;

    if (M == num1){
      start++; now1 = A[start];
    }else if(M == num2){
      end--; now1 = A[end];
    }else if(M == num3){
      start++; now2 = A[start];
    }else{
      end--; now2 = A[end];
    }
  }
  
  cout << ans << endl;

  return 0;
}

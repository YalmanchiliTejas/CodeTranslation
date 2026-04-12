#include <bits/stdc++.h>
using namespace std;
#define rep(i,x) for(int i = 0; i <x; i++)
typedef long long ll;

const ll INF  = 1e11;

int main(){
  int N;
  cin >> N;
  ll A[N];
  rep(i,N) cin >> A[i];

  ll dp[N+2];
  rep(i,N+2) dp[i] = -1;

  rep(i,N){
    int l = -1, r = N;
    while(l+1 < r){
      int mid = (l+r)/2;
      if(dp[mid] < A[i]) r = mid;
      else  l = mid;
    }
    if(dp[l] == A[i]) dp[r] = A[i];
    else dp[r] = A[i];
  }

  int ans = 0;
  rep(i,N+2) {
    if(dp[i] != -1) ans++;
  }
  cout << ans << endl;
  return 0;
}

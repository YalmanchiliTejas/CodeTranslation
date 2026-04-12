#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

typedef long long ll;

int main(){
  int N;
  ll sum=0,ans=0;
  cin >> N;
  vector<ll> A(N);
  for(int i=0; i<N; i++){
    cin >> A[i];
  }
  for(int i=1; i<N; i++){
    sum += A[i];
  }
  sum %= mod;
  for(int i=0; i<N-1; i++){
    ans += sum * A[i];
    ans %= mod;
    sum -= A[i+1];
    sum %= mod;
  }
  if(ans >= 0) cout << ans;
  else cout << ans+mod;
  return 0;
}
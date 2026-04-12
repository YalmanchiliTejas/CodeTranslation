#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  ll N,K;
  cin >> N >> K;

  ll a,b;
  ll ans = 0;
  if(K==0){
    ans = N*N;
  } else{
    for(b = K+1; b <= N; b++){
      ll tmp = (N-b+1)/b;
      ans += (b-K) * (tmp+1);

      ll tmp2 = (tmp + 1) * b + K;
      if(tmp2 <= N){
        ans += N - tmp2 + 1;
      }
    }
  }
  cout << ans << endl;
}
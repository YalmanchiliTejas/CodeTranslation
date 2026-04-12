#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>

using namespace std;

typedef long long ll;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  ll N, K; cin >> N >> K;
  ll cnt = 0;
  if(K == 0){
    cout << N*N << endl;
  }else{
    for(ll b=1;b<=N;b++){
      cnt += max(0LL, (N / b) * (b - K)) + max(0LL, N %b - K + 1);
    }
    cout << cnt << endl;
  }
}
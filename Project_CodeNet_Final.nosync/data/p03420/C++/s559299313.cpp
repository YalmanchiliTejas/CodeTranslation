#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
#define REP(i, limit) for(int i=0; i< limit; ++i)
#define LINT long long

int main(){
  int N, K;
  cin >> N >> K;
  LINT ans=0;
  for(int b = K+1; b<N+1; ++b){
    ans += (N/b)*(b-K);
    if(K) ans += max(0, N%b - K+1);
    else ans += max(0, N%b);
  }

  cout << ans << endl;

  return 0;
}

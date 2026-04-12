#include <math.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll q[51];
ll p[51];

ll solve(ll X, int N){
  if(X == 0){
    return 0;
  }else if(N == 0){
    return 1;
  }else if(X >= q[N]){
    return p[N];
  }else if(X > q[N-1] + 2){
    return solve(X-q[N-1]-2, N-1) + 1 + p[N-1];
  }else if(X == q[N-1] + 2){
    return p[N-1] + 1;  
  }else if(X < q[N-1] + 2) {
    return solve(X-1, N-1);
  }
}

int main(void){
  int N;
  ll X;
  cin >> N >> X;

  q[0] = 1;
  p[0] = 1;
  for(int i=0; i<N; i++){
    q[i+1] = 2*q[i] + 3;
    p[i+1] = 2*p[i] + 1;
//    cout << p[i+1] << endl;
  }
//  cout << q[N] << endl;
  ll ans = solve(X, N);
  cout << ans << endl;  
  return 0;
}
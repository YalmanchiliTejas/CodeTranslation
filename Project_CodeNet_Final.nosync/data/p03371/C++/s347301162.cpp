#include <bits/stdc++.h>
using namespace std;

#define REPS(i, a, n) for (int i = (a); i < (n); ++i)
#define REP(i, n) REPS(i, 0, n)
#define RREP(i, n) REPS(i, 1, n + 1)
#define DEPS(i, a, n) for (int i = (a); i >= n; --i)
#define DEP(i, n) DEPS(i, n, 0)

#define vint(v, n) vector<int> v(n); REP(i,n) cin >> v[i];
#define vints(v, v1, n) vector<int> v(n), v1(n); REP(i,n) cin >> v[i] >> v1[i];

int main(void){

  cin.tie(0);
  ios::sync_with_stdio(false);

  int A, B, C, X, Y;
  int ans = 0;
  cin >> A >> B >> C >> X >> Y;

  if(A+B >= C*2){
    int Z = min(X, Y);
    ans += 2*Z*C;
    if(X == max(X, Y) && A < C*2){
      ans += (X-Z)*A;
    }else if(X == max(X, Y) && A >= C*2){
      ans += (X-Z)*C*2;
    }else if(Y == max(X, Y) && B < C*2){
      ans += (Y-Z)*B;
    }else{
      ans += (Y-Z)*2*C;
    }
  }else{
    if(A < C*2 && B < C*2){
      ans += X*A+Y*B;
    }else if(A >= C*2 && B < C*2){
      ans += X*2*C+Y*B;
    }else if(A < C*2 && B >= C*2){
      ans += X*A+Y*2*C;
    }else{
      ans += 2*C*(X+Y);
    }
  }
  cout << ans << endl;

  return 0;
}

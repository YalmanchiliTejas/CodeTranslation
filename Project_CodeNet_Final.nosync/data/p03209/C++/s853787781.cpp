#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  int N;
  cin >> N;
  long long X;
  cin >> X;
  vector<long long> burger(N + 1);
  burger[0] = 1;
  vector<long long> p(N + 1);
  p[0] = 1;
  for (int i = 1; i <= N; i++) {
    burger[i] = 2 * burger[i - 1] + 3;
    p[i] = 2 * p[i - 1] + 1;
  }
  if(X == burger[N]){
    cout << p[N] <<endl;
    return 0;
  }
  int n = N-1;
  long long ans = 0;
  while(X > 0){
    X--;
    if(X - burger[n] >= 0){
      X -= burger[n]; 
      ans += p[n];
      if(X == 0){
        cout << ans <<endl;
        return 0;
      } else{
        ans ++;
      }
    } else{
      n--;
    }
  }
  cout << ans <<endl;
}
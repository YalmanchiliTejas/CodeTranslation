# include <bits/stdc++.h>
# define INF 1e9
using namespace std;

int main(){

  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int ans = INF;
  int upper = 2*max(X, Y);
  for(int i=0; i<=upper; i+=2){
    int v = i*C;
    v += max(X-i/2, 0)*A;
    v += max(Y-i/2, 0)*B;
    ans = min(ans, v);
  }

  cout << ans << endl;

}
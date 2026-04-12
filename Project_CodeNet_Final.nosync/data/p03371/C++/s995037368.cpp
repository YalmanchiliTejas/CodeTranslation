#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  C *= 2;
  int ans = 2'000'000'000;
  for(int i = 0; i <= 100'000; i++){
    int sum = i*C + max(0, X-i)*A + max(0, Y-i)*B;
    ans = min(ans, sum);
  }
  cout << ans << endl;
}
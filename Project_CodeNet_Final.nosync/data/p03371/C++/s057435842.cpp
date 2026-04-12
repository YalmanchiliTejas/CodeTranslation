#include<bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;

int main(){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  long long ans = INF;
  for(int i = 0; i <= 200000; i += 2){
    int p = x, q = y;
    long long cnt = i * c;
    p = max(0, p - i / 2);
    q = max(0, q - i / 2);
    ans = min(ans, cnt + p * a + q * b);
  }
  cout << ans << endl;
}
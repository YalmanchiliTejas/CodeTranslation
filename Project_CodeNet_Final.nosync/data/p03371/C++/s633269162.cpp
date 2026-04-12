#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  long long ans = 1000000000000000;
  for(int i = 0; i <= 100000; i++){
    long long tmp = 0;
    tmp += 2 * c * i + a * max(0, x-i) + b * max(0, y - i);
    ans = min(tmp,ans);
  }
  cout << ans << endl;
}
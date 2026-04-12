#include <bits/stdc++.h>
#define rep(i,n); for (ll i = 0; i < n ;++i )
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int r,a,b;
  cin >> r >> a >> b;
  if((r*100+a*10+b)%4 == 0){
    puts("YES");
    return 0;
  }
  puts("NO");
  return 0;
}

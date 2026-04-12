#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i<n;++i)
using ll = long long;
using P = pair<int,int>;

int main(){
  int x;
  cin >> x;
  bool f = false;
  if(x == 3) f = true;
  if(x == 5) f = true;
  if(x == 7) f = true;
  if(f) puts("YES");
  else puts("NO");
  return 0;
}

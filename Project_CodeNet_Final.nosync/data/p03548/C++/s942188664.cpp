#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i<n;++i)
using ll = long long;
using P = pair<int,int>;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  a -= c;
  cout << a/(b+c) << endl;
  return 0;
}

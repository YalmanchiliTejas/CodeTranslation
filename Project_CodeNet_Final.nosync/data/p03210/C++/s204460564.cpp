#include <iostream>
using namespace std;

using ll = long long;

#define for_(i, a, b) for(int i = (a);i < (b);++i)
#define rfor_(i, a, b) for(int i = (b)-1;i >= (a);--i)
#define rep(i, n) for_(i, 0, n)
#define rrep(i, n) rfor_(i, 0, n)


int main() {
  cin.tie(0);cout.tie(0);
  ios_base::sync_with_stdio(false);

  int X;
  cin>>X;

  if(X==3||X==5||X==7)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;

  return 0;
}

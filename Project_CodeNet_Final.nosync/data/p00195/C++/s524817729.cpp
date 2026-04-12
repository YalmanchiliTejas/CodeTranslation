#include <iostream>
using namespace std;

#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n) REP(i,0,n)

int am[5], pm[5];

void solve() {
  rep(i,4) cin>>am[i+1]>>pm[i+1];
  
  int res = 0, max = am[0]+pm[0];
  rep(i,4) {
    int t = am[i+1]+pm[i+1];
    if (t > max) {
      max = t;
      res = i+1;
    }
  }
  
  char c = 'A'+res;
  cout<<c<<" "<<max<<endl;
}

int main (int argc, char const* argv[]) {
  while (cin>>am[0]>>pm[0], am[0]||pm[0]) {
    solve();
  }
  return 0;
}
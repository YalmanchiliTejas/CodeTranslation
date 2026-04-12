#include <iostream>
#include <algorithm>
using namespace std;

#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n) REP(i,0,n)

int n, score[100];

void solve() {
  rep(i,n) cin>>score[i];

  sort(score, score+n);
  double sum = 0;
  REP(i,1,n-1) sum += score[i];
  
  cout<<(int)(sum/(n-2))<<endl;
}

int main (int argc, char const* argv[]) {
  while (cin>>n, n) {
    solve();
  }
  return 0;
}
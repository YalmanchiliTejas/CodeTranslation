#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)

using namespace std;

int main() {
  int n,l,r;
  while( cin >> n >> l >> r , n | l | r) {
    vector<int> A(n);
    rep(i,n) cin >> A[i];
    int cnt = 0;
    REP(x,l,r+1) {
      rep(i,n) {
	if( x % A[i] == 0 ) {
	  if( ( i + 1 ) & 1 ) {
	    ++cnt;
	  }
	  goto Skip;
	}
      }
      if( !( n & 1 ) ) ++cnt;
    Skip:;
    }
    cout << cnt << endl;
  }
  return 0;
}


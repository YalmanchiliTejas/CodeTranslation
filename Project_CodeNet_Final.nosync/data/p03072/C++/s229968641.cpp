#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

#define REP(i,n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> pint;

int main() {
  int ans = 0, N;
  cin>>N;
  vector<int> h(N);
  REP(i,N) cin>>h[i];
  REP(i,N) {
    bool ok = true;
    for(int j =	i-1; j >= 0; j--) {
      if(h[j]>h[i]) {
	ok = false; break;
      } 
    }
    if(ok) ans++;
  }
  cout << ans << endl;
  return 0;
}

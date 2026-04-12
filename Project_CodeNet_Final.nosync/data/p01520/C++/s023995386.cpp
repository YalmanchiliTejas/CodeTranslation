#include<iostream>
 
using namespace std;
 
#define rep(i, n) for (int i = 0; i < int(n); ++i)
 
int x[111];
 
int main() {
  int n, t, e;
  cin >> n >> t >> e;
  rep (i, n) cin >> x[i];
  rep (i, n) {
    for (int time = 0; time <= t + e; time += x[i]) {
      if (t - e <= time) {
	cout << i + 1 << endl;
	return 0;
      }
    }
  }
  cout << -1 << endl;
  return 0;
}
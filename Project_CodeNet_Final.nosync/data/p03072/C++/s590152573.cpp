#include <bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
  	int mx = 0, ret = 0;
  	for (int i = 0; i < n; i++) {
    	int x; cin >> x;
      	if (x >= mx) ret++;
      	mx = max(x,mx);
    }
  	cout << ret << endl;
}
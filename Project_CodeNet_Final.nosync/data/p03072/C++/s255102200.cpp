#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define ll long long
#define be(v) v.begin(), v.end()

int main() {
	int n; cin >> n;
	int v[n]{};
  	rep(i,n) cin >> v[i];
	int ma = 0; int count = 0;
	rep(i,n) {
		if(v[i]>=ma) count ++;
		ma = max(ma,v[i]);
	}
	cout << count << endl;
}
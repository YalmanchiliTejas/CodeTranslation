#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

int main() {
	int n; 
	while (cin >> n, n) {
		int c[3];
		int cnt = 1;
		c[0] = 1; c[1] = 2; c[2] = 3;
		rep(i, n) {
			string s; cin >> s;
			int d = c[0];
			if (s == "North") { c[0] = c[1]; c[1] = 7 - d; }
			if (s == "East") { c[0] = 7 - c[2]; c[2] = d; }
			if (s == "West") { c[0] = c[2]; c[2] = 7 - d; }
			if (s == "South") { c[0] = 7 - c[1]; c[1] = d; }
			d = c[1];
			if (s == "Right") { c[1] = c[2]; c[2] = 7 - d; }
			if (s == "Left") { c[1] = 7 - c[2]; c[2] = d; }
			cnt += c[0];
		}
		cout << cnt << endl;
	}
	return 0;
}
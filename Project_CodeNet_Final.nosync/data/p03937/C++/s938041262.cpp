#include <bits/stdc++.h>
using namespace std;
int H, W;
vector<string> A;
bool f() {
	int p = 0;
	for (auto& x : A) {
		if (x[p] != '#') return false;
		x[p] = '$';
		while (p+1 < W && x[p+1] == '#') {
			x[++ p] = '$';
		}
	}
	if (p != W-1) return false;
	for (auto& x : A) {
		for (char c : x) if (c == '#') return false;
	}
	return true;
}
int main() {
	cin >> H >> W;
	A.resize(H);
	for (auto& x : A) cin >> x;
	cout << (f() ? "Possible" : "Impossible") << endl;
}

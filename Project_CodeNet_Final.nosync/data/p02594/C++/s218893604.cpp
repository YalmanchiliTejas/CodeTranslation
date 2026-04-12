#include<bits/stdc++.h>

using namespace std;

void fastio() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
}

int main() {
	fastio();
	int n; cin >> n;
	if (n >= 30) cout << "Yes";
	else cout << "No";
	return 0;
}
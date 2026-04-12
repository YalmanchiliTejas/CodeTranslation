#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int main() {
	int N;
	cin >> N;
	int h = 0;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		int H;
		cin >> H;
		if (H >= h) ans++;
		h = max(h, H);
	}
	cout << ans << endl;
}
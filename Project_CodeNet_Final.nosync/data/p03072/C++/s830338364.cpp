#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;

int main() {
	int N;
	cin >> N;
	int h_max = INT_MIN, ans = 0;
	for(int i = 0; i < N; i++) {
		int H;
		cin >> H;
		if(h_max <= H)
			ans++;
		h_max = max(h_max, H);
	}
	cout << ans << endl;
}

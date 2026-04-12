#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int N;
	cin >> N;

	int ans = 0;
	int max = 0;
	for (int ii = 0; ii < N; ++ii){
		int h;
		cin >> h;
		if (max <= h){
			ans++;
			max = h;
		}
	}

	cout << ans << "\n";


	return 0;
}

#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, H[20];
	cin >> N ;
	for (int i = 0; i < N; i++) cin >> H[i];

	int ans = 0;
	for (int i = 0; i < N; i++) {
		bool f = true;
		for (int j = 0; j <= i; j++) {
			if (H[i] < H[j]) f = false;
		}
		if (f) ans++;
	}
	
	cout << ans << endl;

	return 0;
}
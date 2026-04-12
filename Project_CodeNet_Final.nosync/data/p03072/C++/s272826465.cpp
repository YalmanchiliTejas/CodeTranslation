#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<stdio.h>
#include<vector>
#include<map>
using namespace std;

int N,H[21];
int ans;

int main() {
	cin >> N;
	cin >> H[0];
	ans = 1;
	for (int i = 1; i < N; i++) {
		cin >> H[i];
		if (H[0] <= H[i]) {
			ans++;
			H[0] = H[i];
		}
	}


	cout << ans << endl;

	return 0;
}
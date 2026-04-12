#include <iostream>
#include <algorithm>
#include <string> 
#include <vector>
#include <iomanip>
using namespace std;
#define lol long long


int main()
{
	int N;
	cin >> N;
	vector<int> H(N);
	for (int i = 0; i < N; i++) {
		cin >> H[i];
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		bool OK = true;
		for (int j = i; j >= 0; j--) {
			if (H[i] < H[j]) {
				OK = false;
			}
		}
		if (OK) {
			ans++;
		}
	}
	cout << ans << endl;
}
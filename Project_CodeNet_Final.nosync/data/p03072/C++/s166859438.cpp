#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	int N,ans=0;
	int judge;
	cin >> N;
	vector<int> H(N);
	for (int i = 0; i < N; i++) {
		cin >> H[i];
	}
	for (int i = 0; i < N; i++) {
		judge = 0;
		for (int k = 0; k < i; k++) {
			if (H[i] < H[k]) {
				break;
			}
			else judge++;
			
		}
		if (judge == i) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int main() {
	int N;
	int ans = 1;
	int max = 0;

	cin >> N;
	
	vector<int> H(N);

	for (int i = 0; i < N; i++) {
		cin >> H[i];
	}
	
	for (int k = 1; k < N; k++) {
		for (int i = 0; i < k; i++) {
			if (max < H[i]) {
			max = H[i];
		}

    	}		
		if (max <= H[k])ans++;
		max = 0;
	}

	cout << ans;
	return 0;
}
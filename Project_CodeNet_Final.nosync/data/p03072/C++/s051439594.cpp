#include <bits/stdc++.h>
using namespace std;
    
int main() {
	int N, S = 0;
	cin >> N;
	vector<int> H(N);
	for (int i = 0; i < N; i++) {
		cin >> H.at(i);
	}

	bool ishigher;
	for (int i = 0; i < N; ++i){
		ishigher = true;
		for (int j = 0; j < i; ++j) {
			if (H.at(j) > H.at(i)) {
				ishigher = false;
			}
		}
		if (ishigher) {
			S++;
		}
	}

	cout << S << endl;
}
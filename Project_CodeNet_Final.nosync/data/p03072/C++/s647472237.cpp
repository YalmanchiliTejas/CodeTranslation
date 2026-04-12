#include<iostream>
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

#include<cstdio>

#define FOR(i, n) for(int i = 0; i < (n); i++)
#define FORq(i, m, n) for(int i = (m); i < (n); i++)
#define FORr(i, n) for (int i = (n); i >= 0; i++)


int main() {
	int N, answer;
	cin >> N;
	vector<int> H(N);
	for (int i = 0; i < N; i++) {
		cin >> H[i];
	}

	answer = 1;
	bool ok = true;

	for (int i = 1; i < N; i++) {
		ok = true;
		for (int j = 0; j < i; j++) {
			if (H[j] <= H[i]) {
				continue;
			}
			ok = false;
			break;
		}
		if (ok) {
			answer++;
		}
	}

	cout << answer << endl;
}
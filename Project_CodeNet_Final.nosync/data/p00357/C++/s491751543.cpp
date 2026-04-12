#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> Trampoline;

int main() {
	int d, nextPos;

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> d;
		Trampoline.push_back(d/10);
	}

	for (int cnt = 0; cnt < 2; ++cnt) {
		nextPos = 0;
		for (int startPos = 0; startPos < N; ++startPos) {
			if (nextPos < startPos) {
				cout << "no" << endl;
				return 0;
			}
			nextPos = max(nextPos, startPos + Trampoline[startPos]);
		}
		reverse(Trampoline.begin(), Trampoline.end());
	}
	cout << "yes" << endl;

	return 0;
}

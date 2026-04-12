#include <bits/stdc++.h>

using namespace std;

int Edges[100];

int main() {
	int len;

	memset(Edges, 0, sizeof(Edges));
	for (int i = 0; i < 12; ++i) {
		cin >> len;
		++Edges[len - 1];
	}

	for (int i = 0; i < 100; ++i) {
		if (Edges[i] == 0) {
			continue;
		}
		if (Edges[i] % 4 != 0) {
			cout << "no" << endl;
			return 0;
		}
	}
	cout << "yes" << endl;

	return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool used[100001];
vector <int> connect[100001];




bool search_leaf(int parent, int elem) {
	for (int i = 0; i < connect[elem].size(); i++) {
		int child = connect[elem].at(i);
		if (child == parent) continue;

		bool find_leaf = search_leaf(elem, child);
		if (find_leaf) {
			if (used[elem]) {
				// out
				used[elem] = false;
				return false;
			} else {
				used[elem] = true;
			}
		}
	}

	if (!used[elem]) {
		used[elem] = true;
		return true;
	}
	else return false;
}

int main(void) {
	int N;
	cin >> N;

	if (N%2==1) {
		cout << "First" << endl;
		return 0;
	}

	for (int i = 1; i <= N; i++) {
		used[i] = false;
		connect[i].clear();
	}

	for (int i = 1; i <= N-1; i++) {
		int a, b;
		cin >> a >> b;
		connect[a].push_back(b);
		connect[b].push_back(a);
	}

	int elem = 0;
	(void)search_leaf(-1, 1);

	bool firstWin = false;
	for (int i = 1; i <= N; i++) {
		if (!used[i]) {
			firstWin = true;
			break;
		}
	}

	if (firstWin) {
		cout << "First" << endl;
	} else {
		cout << "Second" << endl;
	}
	return 0;
}

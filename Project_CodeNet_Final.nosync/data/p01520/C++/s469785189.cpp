#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int N, T, E;
	vector<int> x;

	cin >> N >> T >> E;
	for(int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		x.push_back(tmp);
	}

	for(int i = 0; i < x.size(); i++) {
		if(T - E <= x[i] * (((T - E - 1) / x[i]) + 1) && x[i] * (((T - E - 1) / x[i]) + 1) <= T + E) {
			cout << i + 1 << endl;
			return 0;
		}
	}

	cout << "-1" << endl;
	return 0;
}
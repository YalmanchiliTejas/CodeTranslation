#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <cmath>

using namespace std;

int main() {
	int n, m;
	while (cin >> n >> m) {
		if (n == 0 && m == 0) {
			break;
		}
		priority_queue< long long int, vector<long long int>, greater<long long int> >pq;
		long long int a;
		for (int i = 0; i < n; i++) {
			cin >> a;
			pq.push(a);
		}
		for (int i = 0; i < m; i++) {
			cin >> a;
			pq.push(a);
		}
		a = pq.top();
		pq.pop();
		long long int MAX = a;
		while (!pq.empty()) {
			long long int b = pq.top();
			pq.pop();
			MAX = max(MAX, b-a);
			a = b;
		}
		cout << MAX << endl;
	}
	return 0;
}
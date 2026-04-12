#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	const int limit = 10000;

	for(int n, a, b, c, x; cin >> n >> a >> b >> c >> x, n;) {
		int time = -1;
		vector<int> y(n);
		for(int i = 0; i < n; ++i)
			cin >> y[i];

		for(int i = 0; i < n; ++i) {
			++time;
			while(x != y[i]) {
				if(++time > limit) {
					time = -1;
					goto finish;
				}

				x = (a * x + b) % c;
			}

			x = (a * x + b) % c;
		}

	finish:;

		cout << time << endl;
	}

	return EXIT_SUCCESS;
}
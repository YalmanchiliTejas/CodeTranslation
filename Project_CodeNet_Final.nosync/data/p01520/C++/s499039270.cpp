#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
	int n, t, e;
	cin >> n >> t >> e;
	
	for(int i=1; i<=n; ++i) {
		int x;
		cin >> x;
		int d = t - x*(t/x);
		if(d <= e || x - d <= e) {
			cout << i << endl;
			return EXIT_SUCCESS;
		}
	}

	cout << -1 << endl;
	return EXIT_SUCCESS;
}
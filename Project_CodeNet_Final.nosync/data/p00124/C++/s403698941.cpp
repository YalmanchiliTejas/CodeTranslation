#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int n, a, b, c, d; pair<int, string> p[10];
int main() {
	while(scanf("%d", &n), n) {
		for(int i = 0; i < n; i++) {
			cin >> p[i].second >> a >> b >> c;
			p[i].first = i - a * 30 - c * 10;
		}
		sort(p, p + n);
		if(d++) printf("\n");
		for(int i = 0; i < n; i++) {
			cout << p[i].second << ',' << (-p[i].first + 9) / 10 << endl;
		}
	}
	return 0;
}
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	int a, b;
	while (cin >> a >> b, a | b) {
		vector<int>c(a+b);
		for (int d = 0; d < a + b; d++)cin >> c[d];
		sort(c.begin(), c.end());
		int s = c[0];
		for (int e = 1; e < a + b; e++)s = max(s, c[e] - c[e - 1]);
		cout << s << endl;
	}
}
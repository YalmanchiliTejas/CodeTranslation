#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
typedef pair<pair<int, int>, string> p;
int main() {
	int n; bool b = false;
	while (cin >> n, n) {
		if (b)cout << endl;
		p l[11];
		for (int i = 0; i < n; i++) {
			cin >> l[i].second;
			int a, b, c; cin >> a >> b >> c;
			l[i].first = make_pair(a * 3 + c, n - i);
		}
		sort(l, l + n);
		for (int i = n - 1; i >= 0; i--) {
			cout << l[i].second << ',' << l[i].first.first << endl;
		}
		b = true;
	}
}
#include <iostream>
#include <cstdio>
using namespace std;

int n, m, mx, t;
string a;
int main()
{
	int i, j;
//	freopen ("input.txt", "r", stdin);
	cin >> n >> m;
	mx = 0;
	for (i = 0; i < n; i++) {
		cin >> a;
		t = 0;
		for (j = 0; j < a.size(); j++) {
			if (a[j] == '#' && j < mx) {
				cout << "Impossible";
				return 0;
			}
			if (a[j] == '.' && j == mx) {
				cout << "Impossible";
				return 0;
			}
			if (a[j] == '#') t = j;
		}
		mx = t;
	}
	if (mx != m - 1) {
		cout << "Impossible";
		return 0;
	}
    cout << "Possible" << endl;
    return 0;
}

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<functional>
#include<queue>
using namespace std;
int main() {
	int a[1000000];
	bool a2[1000000];
	int n;
	while (cin >> n&&n != 0) {
		int c = 0;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			bool l = x == 1 ? 1 : 0;
			if (c == 0) {
				a[0] = 1;
				a2[0] = l;
				c++;
			}
			else if (i % 2 == 0) {
				if (a2[c - 1] == l) {
					a[c - 1]++;
				}
				else {
					a[c] = 1;
					a2[c] = l;
					c++;
				}
			}
			else {
				if (a2[c - 1] == l) {
					a[c - 1]++;
				}
				else {
					if (c >= 2) {
						a[c - 2] += a[c - 1];
						a[c - 2]++;
						c--;
					}
					else {
						a[c - 1]++;
						a2[c-1] = l;
					}
				}
			}
		}
		int sum = 0;
		for (int i = 0; i < c; i++) {
			if (!a2[i]) {
				sum += a[i];
			}
		}
		cout << sum << endl;
	}
}
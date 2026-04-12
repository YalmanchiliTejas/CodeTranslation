#include<iostream>
#include<algorithm>
using namespace std;
int maxn, n, m, y, money, money2, a, c; double b;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> money; money2 = money;
		cin >> y >> m; maxn = 0;
		for (int j = 0; j < m; j++) {
			cin >> a >> b >> c; money = money2;
			if (a == 1) {
				for (int k = 0; k < y; k++) {
					money = (double)money*(1 + b);
					money -= c;
				}
			}
			else {
				for (int k = 0; k < y; k++) {
					money += (double)(money2 - k*c)*b;
				}
				money -= y*c;
			}
			maxn = max(maxn, money);
		}
		cout << maxn << endl;
	}
}
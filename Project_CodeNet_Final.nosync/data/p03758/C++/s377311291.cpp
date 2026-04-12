#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<functional>
#include<list>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<string.h>
#include<limits.h>
using namespace std;

signed main() {
	vector<int>x, y;
	int a; cin >> a;
	for (int b = 0; b < a; b++) {
		for (int c = b + 1; c < a; c++) {
			string d="? ";
			for (int e = 0; e < a; e++) {
				if (b == e || c == e) {
					d += '1';
				}
				else {
					d += '0';
				}
			}
			cout << d << endl;
			int n; cin >> n;
			if (n) {
				x.push_back(b); y.push_back(c);
			}
		}
	}
	cout << "!";
	for (int i = 0; i < x.size(); i++) {
		cout << ' ';
		cout << '(' << x[i] << ',' << y[i] << ')';
	}
	cout << endl;
}
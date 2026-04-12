#include <iostream>
#include <vector>
#include <utility>
#include<algorithm>
#include<stack>
#include<queue>
#include<list>
#include<array>
using namespace std;

int main() {
	int k = 100000;
	int n;
	cin >> n;
	vector<int>u(n);
	vector<int>v(n + 1);
	for (int i = 0;i < n+1; i++) {
		v.at(i) = -1;
	}
	for (int i = 0; i < n; i++) {
		cin >> u.at(i);
	}
	for (int i = 0; i < n; i++) {
		int j = 0;
		int min = 0;
		int max = n;
		int mid = n / 2;
		while ((max-min)>1) {
			mid = (max + min) / 2;
			if (v.at(mid) >= u.at(i)) {
				min = mid;
			}
			else {
				max = mid;
			}
		}
		if (u.at(i) > v.at(min)) {
			v.at(min) = u.at(i);
		}
		else
			v.at(max) = u.at(i);
	}
	int c = 0;
	while (v.at(c) > -1) {
		c++;
	}
	cout << c << endl;
	return 0;
}
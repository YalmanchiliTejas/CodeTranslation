#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>

using namespace std;


int main() {
	vector<int> r;
	int n, c=0;
	cin >> n;
	r.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> r[i];
	}

	c++;//最も西からは見える
	if(n>1)
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (r[i] >= r[j]) {
					if (j == i-1) {
						c++;
					}
				}
				else {
					break;
				}
			}
		}

	cout << c << endl;

	return 0;
}

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <iomanip>
#define ll long long
#define REP(i, x) for(int (i) = 0; (i) < (x); (i) ++)
using namespace std;

int main() {
	int n, count, j;
	count = 0;
	int h[20];
	cin >> n;
	REP(i, n) {
		cin >> h[i];
	}
	REP(k, n) {
		if (k == 0) {
			count++;
		}
		else {
			for (j = 0; j <= k; j++) {
				if (h[j] > h[k]) {
					break;
				}
				else {
					if (j == k) {
						count++;
					}
				}
			}
		}
	}
	cout << count << endl;
	return 0;
}
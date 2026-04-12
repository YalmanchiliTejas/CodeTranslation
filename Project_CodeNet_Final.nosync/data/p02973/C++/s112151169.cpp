#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include <math.h>
#include <cmath>
#include <vector>
#include <deque>
#include <algorithm>

typedef long long ll;
typedef unsigned long long ull;
#define mod 1000000007
#define rep(i, n) for(int i = 0; i < n; ++i)

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	int* a;
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> t;
	t.push_back(a[n - 1]);
	for (int i = n - 2; i >= 0; i--) {
		if (a[i] >= t[t.size() - 1]) {
			t.push_back(a[i]);
			continue;
		}
		
		int left = 0;
		int right = t.size();
		int mid;
		while (left < right) {
			mid = (left + right) / 2;

			if (a[i] < t[mid]) {
				right = mid;
				if (mid == 0) {
					t[mid] = a[i];
					break;
				}
			}
			else {
				left = mid;
				if (mid == right - 1) {
					t[right] = a[i];
					break;
				}
			}
		}
	}

	cout << t.size() << "\n";
 }

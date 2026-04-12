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
	t.push_back(n - 1);
	for (int i = n - 2; i >= 0; i--) {
		if (a[i] >= a[t[t.size() - 1]]) {
			t.push_back(i);
			continue;
		}
      
		for (int j = 0; j < t.size(); j++) {
			if (a[i] < a[t[j]]) {
				t[j] = i;
				break;
			}
		}
	}

	cout << t.size() << "\n";
 }

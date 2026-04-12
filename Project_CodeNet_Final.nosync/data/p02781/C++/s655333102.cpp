#include <bits/stdc++.h>
using namespace std;

constexpr int EQUAL = 0;
constexpr int LESS_THAN = 1;
constexpr int GREATER_THAN = 2;

int l;
vector<int> n;
vector<int> a;

int f(int pos, int count, char cmp = 0) {
	int res = 0;

	if (count == 0 && cmp != GREATER_THAN) {
		return 1;
	}

	if (pos == l || cmp == GREATER_THAN) {
		return 0;
	}
	
	for (int d = 0; d < 10; ++d) {
		a[pos] = d;
		if (d != 0) {
			--count;
		}

		char cmp2 = cmp;
		if (cmp2 == EQUAL) {
			if (a[pos] < n[pos]) {
				cmp2 = LESS_THAN;
			} else if (a[pos] > n[pos]) {
				cmp2 = GREATER_THAN;
			}
		}

		res += f(pos + 1, count, cmp2);

		if (d != 0) {
			++count;
		}
		a[pos] = 0;

		if (cmp2 == GREATER_THAN) {
			break;
		}
	}

	return res;
}

int main() {
	string s;
	int k;

	cin >> s >> k;
	
	l = s.length();
	n = vector<int>(l);
	a = vector<int>(l);
	for (int i = 0; i < l; ++i) {
		n[i] = s[i] - '0';
		a[i] = 0;
	}

	cout << f(0, k);
	
	return 0;
}
	
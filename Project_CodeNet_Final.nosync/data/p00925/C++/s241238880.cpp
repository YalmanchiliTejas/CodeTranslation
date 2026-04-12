#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int ite;
int n;
string ex;

ll num();
ll L();
ll exp();
ll fac();

ll num() {
	assert(ite < n && isdigit(ex[ite]));
	ll res = 0;
	while (ite < n && isdigit(ex[ite])) {
		res += ex[ite] - '0';
		ite++;
	}
	return res;
}

ll L() {
	ll res = num();
	while (ite < n) {
		if (ex[ite++] == '+') {
			res += num();
		}
		else {
			assert(ex[ite - 1] == '*');
			res *= num();
		}
	}
	return res;
}

ll exp() {
	ll res = fac();
	while (ite < n) {
		assert(ex[ite] == '+');
		ite++;
		res += fac();
	}
	return res;
}

ll fac() {
	ll res = num();
	while (ite < n && ex[ite] == '*') {
		ite++;
		res *= num();
	}
	return res;
}

int main()
{
	ll val;
	cin >> ex >> val;
	n = ex.size();
	bool l = L() == val;
	ite = 0;
	bool m = exp() == val;
	cout << (m ? l ? 'U' : 'M' : l ? 'L' : 'I') << endl;
	return 0;
}
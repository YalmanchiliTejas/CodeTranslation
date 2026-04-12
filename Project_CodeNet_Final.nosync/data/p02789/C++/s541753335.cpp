#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const long long mod = 1e9 + 7;

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}



int main() {
	int n,m;
	cin >> n >> m;

	if (n == m) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	
}

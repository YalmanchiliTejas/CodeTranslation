#include <bits/stdc++.h>
using namespace std;

string n;
int k;

int comb(int n, int k) {
	int rv = 1;
	for (int i = 0; i < k; i++)
		rv *= n--;
	while (k)
		rv /= k--;
	return rv;
}

int g(int free, int k) {
	return comb(free, k) * pow(9, k);
}

int f(string n, int k) {
	if (k == 0)
		return 1;
	if (n.size() < k)
		return 0;
	int init = n[0] - '0';
	if (init) {
		return f(n.substr(1), k - 1) + (init - 1) * g(n.size() - 1, k - 1)
				+ g(n.size() - 1, k);
	}
	return f(n.substr(1), k);
}

int main() {
	cin >> n >> k;
	cout << f(n, k) << endl;

}

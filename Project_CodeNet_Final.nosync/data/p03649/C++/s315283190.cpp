#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 52;

int n;
ll a[Maxn];
ll k;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ll tims = (a[i] + k) / n;
		k += tims; a[i] -= tims * ll(n + 1); 
	}
	bool ch = true;
	while (ch) {
		ch = false;
		for (int i = 0; i < n; i++)
			while (a[i] + k >= n) {
				ch = true;
				ll tims = (a[i] + k) / n;
				k += tims; a[i] -= tims * ll(n + 1);
			}
	}
	cout << k << endl;
	return 0;
}
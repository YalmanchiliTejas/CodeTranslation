#include <iostream>
#include <algorithm>
#include <array>
#include <math.h>
#include <set>
#include <stdlib.h>
#include <string>
#include <vector>

#define INT_MAX 2000000000
#define MOD 1000000007
#define ll long long
#define rep(i,a,b) for(i = (a); i < (b); i++)
#define bitget(a,b) (((a) >> (b)) & 1)

using namespace std;



int main() {
	int i, j, k;
	int n;
	cin >> n;
	int a[200000];
	int b[200000] = {};
	rep(i, 0, n)
		cin >> a[i];
	int m = 0;
	for (i = n - 1;i > -1;i -= 2) {
		b[m] = a[i];
		m++;
	}
	for (i = n % 2;i < n;i += 2) {
		b[m] = a[i];
		m++;
	}
	rep(i, 0, n) {
		cout << b[i];
		if (i != n - 1) {
			cout << " ";
		}
	}
	cout << endl;
	return 0;
}
#include<iostream>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>
#include <functional>
#include <iomanip>
#include <queue>

#define PI 3.14159265358979
#define MOD 1000000007

//fixed << setprecision(15) <<

using namespace std;


int main(void) {
	long long int n, m, max;
	int i, j;
	int e[200000];
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> e[i];
	}
	max = 0;
	m = 0;
	for (i = n - 1; i >0; i--) {
		m += e[i];
		m %= MOD;
		max += e[i - 1] * m;
		max %= MOD;
	}
	cout << max << endl;
	return 0;
}
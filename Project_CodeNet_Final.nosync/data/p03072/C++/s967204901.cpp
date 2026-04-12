#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)


//ABC124_b
int main() {
	int n;
	cin >> n;
	int A[110];
	rep(i, n) cin >> A[i];

	int cnt = 0;
	int mx = 0;
	rep(i, n) {
		if (A[i] >= mx) cnt++;
		mx = max(mx, A[i]);
	}
	cout << cnt << endl;
}
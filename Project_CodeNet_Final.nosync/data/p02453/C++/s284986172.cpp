#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <iomanip>
#define rep(i, n) for (int i = 0; i < (int)(n); i++
using namespace std;

int main() {
	int n,m=0;
	cin>>n;
	vector<int> a(n, 0);
	for (int i = 0; i < n;i++) {
		cin>>a[i];
		m=max(m,a[i]);
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int k; cin >> k;
		if (k > m) {
			cout << n << endl;
		}
		else {
			cout << lower_bound(a.begin(), a.end(), k) - a.begin() << endl;
		}
	}
}



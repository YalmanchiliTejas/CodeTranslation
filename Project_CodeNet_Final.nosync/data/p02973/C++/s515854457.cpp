#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int len[n];
	for (int i = 0; i < n; i++) len[i] = 0;
	vector<int> arr[n];
	for (int i = 0; i < n; i++) {
	    arr[i].push_back(-1);
	}
	int last[n];
	for (int i = 0; i < n; i++) last[i] = -1;
	for (int i = 0; i < n; i++) {
	    int x; cin >> x;
	    int pos = lower_bound(last, last + n, x) - last;
	    pos--;
	    len[pos]++;
	    arr[pos].push_back(x);
	    last[pos] = x;
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
	    if (len[i] != 0) res++;
	}
	cout << res;
}
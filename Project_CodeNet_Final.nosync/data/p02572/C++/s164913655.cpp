#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

using ll = long long;

int addm(int a, int b) {
	return ((ll)a+b)%MOD;
}

int mulm(int a, int b) {
	return ((ll)a*b)%MOD;
}

int main() {
	int n;
  	cin >> n;
  	vector<int> arr(n), pref(n);
  	for(auto &x:arr) cin >> x;
  	pref[0] = arr[0];
  	for(int i = 1; i < n; i++) {
    	pref[i] = addm(pref[i-1], arr[i]);
    }
  	int sum = 0;
  	for(int i = 1; i < n; i++) {
    	sum = addm(sum, mulm(pref[i-1], arr[i]));
    }
  	cout << sum;
}

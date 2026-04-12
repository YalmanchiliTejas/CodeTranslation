#include "bits/stdc++.h"
using namespace std;
#define ll long long
int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	ll n; cin >> n;
	vector<ll> a(n);
	deque<ll> deq;
	for (int i = 0; i < n;i++) {
		cin >> a[i];
		if(i %2 == 0)deq.push_back(a[i]);
		else deq.push_front(a[i]);
	}
	if (n % 2 != 0) {
		for (auto it = deq.rbegin(); it != deq.rend();it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
	else {
		for (auto it = deq.begin();it != deq.end();it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
}
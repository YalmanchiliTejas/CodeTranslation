#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	deque<int> v;
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if(i % 2 == 0) v.push_back(a);
		else v.push_front(a);
	}

	if(n % 2) {
		reverse(v.begin(), v.end());
	}

	for(int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

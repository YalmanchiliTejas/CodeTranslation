#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll K, A, B;
	cin >> K >> A >> B;
	if (A <= B && A < K) {
		cout << -1 << endl;
	}
	else if (A <= B) {
		cout << 1 << endl;
	}
	else {
		cout << min((K + A - B - 1) / (A - B) * 2, (K - A + A - B - 1) / (A - B) * 2 + 1) << endl;
	}
	return 0;
}

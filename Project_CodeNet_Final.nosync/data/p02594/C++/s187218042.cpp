#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	bool isYes = 1;

	int x;
	cin >> x;
	isYes = (x >= 30);

	cout << (isYes ? "Yes" : "No") << endl;
}

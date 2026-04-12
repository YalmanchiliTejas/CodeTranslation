// Problem Code: abc174_a

#include <bits/stdc++.h>

using namespace std;

string A(int X) {
	return (X >= 30) ? "Yes" : "No";
}

int main() {
	int X;
	cin >> X;
	cout << A(X);
	return 0;
}
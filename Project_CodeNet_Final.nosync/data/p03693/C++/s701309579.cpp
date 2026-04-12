#include<bits/stdc++.h>
using namespace std;
int main() {
	char r, g, b;
	cin >> r >> g >> b;
	string ans;
	ans[0] = r;
	ans[1] = g;
	ans[2] = b;
	int sum;
	sum = stoi(ans);
	if (sum % 4 == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}
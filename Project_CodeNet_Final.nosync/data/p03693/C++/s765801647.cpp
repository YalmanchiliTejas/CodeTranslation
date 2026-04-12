#include <bits/stdc++.h>
using namespace std;

int main() {
	string r, g, b; cin >> r >> g >> b;

	string cnt = r + g + b;
	if(stoi(cnt) % 4 == 0) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}
#include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;
int x;
int main() {
	fastio;
	cin >> x;
	cout << (x < 30 ? "No" : "Yes") << '\n';
	return 0;
}
#include <iostream>
using namespace std;
int n, m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	cout << ((n == m) ? string("Yes") : string("No")) << endl;
	return 0;
}

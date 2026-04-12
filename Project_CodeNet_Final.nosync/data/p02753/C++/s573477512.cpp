#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int main() {
	char c1, c2, c3;
	cin >> c1 >> c2 >> c3;

	if (c1 == c2 && c1 == c3) cout << "No" << endl;
	else cout << "Yes" << endl;

	return 0;
}
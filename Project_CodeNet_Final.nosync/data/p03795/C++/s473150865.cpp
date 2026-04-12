#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	int ans = n * 800 - n / 15 * 200;
	cout << ans << endl;
    return 0;
}

# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <cmath>
# include <iomanip>
# include <functional>
# include <utility>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if ((b * 10 + c) % 4 == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}
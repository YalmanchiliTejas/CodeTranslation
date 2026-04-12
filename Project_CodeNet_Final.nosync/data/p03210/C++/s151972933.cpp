#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <functional>
using namespace std;
int main() {
	int a;
	cin >> a;
	if (a == 3 || a == 5 || a == 7) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}


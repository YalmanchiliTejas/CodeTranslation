#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int a, b, c;
	while(cin >> a >> b >> c) {
		a -= c;
		cout << a / (b + c) << endl;
	}
	return 0;
}

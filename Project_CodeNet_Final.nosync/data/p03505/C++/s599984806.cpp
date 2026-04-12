#include <iostream>
#include <cmath>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <tuple>
using namespace std;
long long K, A, B;
int main() {
	cin >> K >> A >> B;
	long long C = A;
	if (C >= K) { cout << "1" << endl; }
	else  if (A <= B) { cout << "-1" << endl; }
	else {
		cout << 1LL + 2LL * (((K - C) + (A - B - 1)) / (A - B)) << endl;
	}
	return 0;
}
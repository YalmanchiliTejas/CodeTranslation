#include <iostream>
#include <stdio.h>
#include <math.h> 
#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

vector<unsigned long  long> a;

int main() {

	int x, y, z;
	cin >> x >> y >> z;

	int n = 0;

	while (1) {
		//今の長さ
		int now_len = n * y + (n + 1)*z;
		if (x < now_len) {
			break;
		}
		n++;
	}

	cout << n-1 << endl;

	return 0;
}
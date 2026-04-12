#include<iostream>
#include<algorithm>
#include<iomanip>
#include<limits>
#include<deque>
#include<string>
#include<map>
#include<set>
#include <unordered_set>
#include<vector>
#include<cmath>

using namespace std;


int main() {
	int h, w; cin >> h >> w;
	char a;
	int i, sum = 0;

	for (i = 0; i < h*w; i++) {
		cin >> a;
		if (a == '.') { sum++; }
	}

	if (sum == (w - 1)*(h - 1)) { cout << "Possible" << endl; }
	else { cout << "Impossible" << endl; }


	return 0;
}
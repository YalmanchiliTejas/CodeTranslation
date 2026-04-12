#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <array>
#include <vector>
#include <functional>
#include <unordered_map> 
#include <map> 
#include <numeric>
#include <limits>
#include <utility>
#include <queue>
#include <random>
using namespace std;
typedef long long LL;

int main(void) {
	string a;
	cin >> a;

	for (int i = 0; i < a.size(); i++) {
		if (a[i] == 'A'&&i!=a.size()-1) {
			if (a[i + 1] == 'C') {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;


	return 0;
}
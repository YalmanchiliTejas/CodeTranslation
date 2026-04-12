#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <numeric>
#include <tuple>

using namespace std;


int main(){
	int x;
	cin >> x;
	if (x == 3 || x == 5 || x == 7) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}
#include <iostream>
#include <cstdlib>
#include<vector>
#include<string>
#include<cmath>
#include <algorithm>
#include<complex>

using namespace std;
typedef long long LL;


int main() {
	LL N;
	LL x=0, y=0;

	cin >> N;

	y = (N/15) * 200;
	x = N * 800;

	cout << x - y << endl;

	return 0;
}

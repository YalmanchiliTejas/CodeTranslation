#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>

#define PI 3.141592653589793238
#define INF 1050000000

using namespace std;



//cout << fixed << setprecision(15) << << endl;
//cout << << endl;

int main() {

	int r,g,b;

	cin >> r >> g >> b;

	int a;

	a = 100 * r + 10 * g + b;

	if (a % 4 == 0) {
		cout << "YES" << endl;

	}
	else {
		cout << "NO" << endl;
	}

	return 0;
}
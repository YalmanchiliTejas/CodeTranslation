#include<algorithm>
#include<climits>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<iostream>
#include<numeric>
#include<string>
#include<utility>
#include<vector>
using namespace std;
//--------------------

int main() {
	double res;
	double r1, r2; cin >> r1 >> r2;

	res = (r1 * r2) / (r1 + r2);
	
	cout << setprecision(20) << res << endl;
}
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <limits>
using namespace std;
#define ll long long
int main(){
	double R1, R2;
	cin >> R1 >> R2;
	double ans = R1*R2/(R1 + R2);
	cout << setprecision(14) << ans << endl;
}
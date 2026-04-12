#include<iostream>
#include<iomanip>

using namespace std;

double r[2], pre = 0, ans = 0;

int main(){
	cin >> r[0] >> r[1];

	pre = 1 / r[0] + 1 / r[1];
	ans = 1 / pre;

	cout << setprecision(12) << ans << "\n";

	return 0;
}
#include<iostream>
#include<cmath>
#include<algorithm>
#include <cassert>
#include<string>
#include<vector>
#include <utility>
#include <math.h>
using namespace std;
int main(){
	int a = 0, b = 0, c = 0, d = 0, e = 0, money = 0;
	cin >> a >> b >> c >> d >> e;
	if (a + b >= c * 2) {
		money += c * 2 * min(d, e);
		if (d > e) {
			d -= e;
			e = 0;
		}
		else if (d < e) {
			e -= d;
			d = 0;
		}
		else if (d = e) {
			cout << money << endl;
			return 0;
		}
	}
	
	while (d != 0) {
		if (c * 2 > a) {
			money += a;
			d--;
		}
		else {
			money += c * 2;
			d--;
		}
	}
	while (e != 0) {
		if (c * 2 > b) {
			money += b;
			e--;
		}
		else {
			money += c * 2;
			e--;
		}
	}
	cout << money << endl;
	return 0;
}
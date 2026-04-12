#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include<algorithm>
#include<sstream>
#include<iomanip>


using namespace std;



int main() {
	int a, b, ab;
	cin >> a >> b >> ab;
	int x, y;
	cin >> x >> y;

	ab *= 2;
	
	
	int money = a * x + b * y;

	int z = min(x, y);
	if (money > ab*z + a*(x - z) + b*(y - z)) {
		money = ab * z + a * (x - z) + b * (y - z);
	}

	if (money > ab*max(x, y)) {
		money = ab * max(x, y);
	}
	cout << money << endl;
}
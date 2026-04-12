#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	std::string str;
	int okasi[100];
	bool abpizza = false;
	int a = 0, b = 0, c = 0, x=0, y=0,price=0;
	std::cin >> a >>b>>c>>x>>y;
	if (c * 2 < a + b) {
		abpizza = true;
	}
	if (abpizza) {
		if (x < y) {
			price = min(c*x*2+b*(y-x),c*y*2);
	}
		else {
			price = min(c*y * 2 + a*(x - y), c*x * 2);
		}
	}
	else {
		price = a*x + b*y;
	}
	std::cout << price << endl;
}

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <functional>
#include <array>
#include <cmath>
#include <set>
#include <iomanip>

using namespace std;


int A, B, C, X, Y;

int main(){
	
	cin >> A >> B >> C >> X >> Y;

	int c = min(X, Y);
	int price = c * min(A + B, 2 * C);
	
	if (X > Y) {
		price += (X - Y)* min(A, 2 * C);
	}
	else {
		price += (Y - X)* min(B, 2 * C);
	}

	cout << price << endl;

	return 0;
}


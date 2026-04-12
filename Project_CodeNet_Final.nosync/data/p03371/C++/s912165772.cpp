#include<iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <math.h>

using namespace std;
int main()
{
	long long A, B, C, X, Y;
	long long price, temp, a, b;

	cin >> A >> B >> C >> X >> Y;

	int MAX = max(X, Y);
	price = X * A + Y * B;

	for (int i = 0; i <= 2 * MAX; i = i + 2) {
		a = (X - i / 2)*A;
		b = (Y - i / 2)*B;
		if (a < 0)a = 0;
		if (b < 0)b = 0;
		temp = i * C + a + b;

		if (temp < price) {
			price = temp;
		}
	}

	cout << price;

	return 0;
}
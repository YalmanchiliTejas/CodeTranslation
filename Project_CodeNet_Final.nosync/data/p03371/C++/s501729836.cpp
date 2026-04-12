#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	int num[3] = { 0, 0, 0 };
	if (A + B > C * 2){
		if (X > Y){
			num[2] += Y * 2;
			if (A > C * 2){
				num[2] += (X - Y) * 2;
			}
			else{
				num[0] += X - Y;
			}
		}
		else{
			num[2] += X * 2;
			if (B > C * 2){
				num[2] += (Y - X) * 2;
			}
			else{
				num[1] += Y - X;
			}
		}
	}
	else{
		num[0] = X;
		num[1] = Y;
	}

	int price;
	price = num[0] * A + num[1] * B + num[2] * C;
	cout << price;

	return 0;
}
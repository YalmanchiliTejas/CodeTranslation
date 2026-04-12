#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<string>
#include<math.h>
using namespace std;

int main() {
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	long m=1000000000;
	int s1 = A * X + B * Y;
	int s2 = C *2* max(X, Y);
	int s3;
	if (X > Y) {
		s3 = C * 2 * Y + A * (X - Y);
	}
	else s3 = C * 2 * X + B * (Y - X);
	s2 = min(s3, s2);

	cout << min(s2,s1);
}
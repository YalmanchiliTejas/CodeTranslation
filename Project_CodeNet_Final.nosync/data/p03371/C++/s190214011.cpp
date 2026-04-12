#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int A,B,C,X,Y;
	cin >> A >> B >> C >> X >> Y;
	int ans = 1000000000;
	for (int i = 0;i < max(X,Y) * 2 + 1;i+=2) {
		int a = X - i/2;
		int b = Y - i/2;
		if (a < 0) a = 0;
		if (b < 0) b = 0;
		ans = min(ans,a*A+b*B+i*C);
	}
	cout << ans;
}
#include<iostream>
#include <algorithm>
#include<string>
using namespace std;

int main(void) {
	long int A,B,C  ;
	long int X, Y;
	long int A_sum ,B_sum= 0;
	long int ans=0;
	cin >> A >> B >> C >> X >> Y;
	if (X > Y) {
		swap(A,B);
		swap(X,Y);
	}
	if (A + B <= C*2)
		ans = X*A + Y*B;
	else {
		ans += X * 2 * C;
		//A買い終わり
		ans += ( Y-X)*min(B, C*2);
		//B end
	}

	cout << ans <<endl;
	return 0;
}
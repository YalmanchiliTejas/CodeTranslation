#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int A,B,C,X,Y;
	cin >> A >> B >> C >> X >> Y;
	int res;
	if ((A+B) < (2*C)) {
		res = (X*A) + (Y*B);
	}
	else {
		if (X < Y) {
			res = min((2*X*C)+((Y-X)*B),(2*Y*C));
		}
		else {
			res = min((2*Y*C)+((X-Y)*A),(2*X*C));
		}
	}
	cout << res << endl;
	return 0;
}

#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;


int main() {
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	int G = max(X, Y);

	long long int R = 100000000000000000;

	for (int i = 0;i<=2*G  ; i += 2) {
		if (((X - i / 2 )<= 0)&&((Y-i/2)<=0)) {
			if (R > i*C) {
				R = i * C;
			}
		}
		if (((X - i / 2) > 0) &&( (Y - i / 2)<=0)) {
			if (R > i*C+A*(X-i/2)) {
				R = (i * C) +( A * (X - i / 2));
			}
		}
		if (((X - i / 2) <= 0) && ((Y - i / 2)>0)) {
			if (R >( i*C+B*(Y-i/2))) {
				R = (i * C )+ (B * (Y - i / 2));
			}
		}
		if (((X - i / 2 )> 0 )&& ((Y - i / 2)>0)) {
			if (R > (i*C+(A*(X-i/2))+((Y-i/2)*B))) {
				R = i * C + (A * (X - i / 2)) + (B*(Y - i / 2));
			}
		}
		
	}
	

	cout << R << endl;
	
	return 0;
}

		
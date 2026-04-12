#include<iostream>
using namespace std;

int main() {
	int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;

	int half =  C * ((X < Y) ? X : Y) * 2 + ((X < Y) ? B*(Y-X) : A*(X-Y));
	int all = A * X  + B * Y;
	int half_2 = C * ((X < Y) ? Y : X) * 2;

	if(half < all) {
		if(half < half_2) cout << half << endl;
		else cout << half_2 << endl;
	} else {
		if(all < half_2) cout << all << endl;
		else cout << half_2 << endl;
	}

	return 0;
}

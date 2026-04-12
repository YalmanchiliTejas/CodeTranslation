#include <iostream>

using namespace std;

int main(){
	int A = 0;
	int B = 0;
	int C = 0;
	int X = 0;
	int Y = 0;
	int cost = 0;
	cin >> A >> B >> C >> X >> Y;
	
	int min = A * X + B * Y;
	int n = min;
	int temp = min;
	int x = 0, y = 0, z = 0;
	for ( int Z = 1;X > 0 || Y > 0; Z++ ) {
		if ( X > 0 ) {
			n -= A;
			X--;
		}
		
		if ( Y > 0 ) {
			n -= B;
			Y--;
		}
		
		temp = n + ( 2 * C * Z );
		if ( temp < min ) {
			min = temp;
			x = X, y = Y, z = Z;
		}
	} // for
	
	cout << min;
} // int main()
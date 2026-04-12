#include <iostream>
#include <string>

using namespace std;

struct _X {
	int back, front;
	int left, right;
	int bottom, top;
};
struct _Y {
	int top, bottom;
	int front, back;
	int left, right;
};
struct _Z {
	int back, front;
	int top, bottom;
	int left, right;
};
class Dice {
private :
	void Swap( int &a, int &b ) { int t = a; a = b; b = t; }
public :
	union {
		_X X;
		_Y Y;
		_Z Z;
		int d[6];
	};
	Dice ( int t, int bt, int f, int bk, int l, int r )
		{ Y.top = t; Y.bottom = bt; Y.front = f; Y.back = bk; Y.left = l; Y.right = r; }
	void RotLeftX	( int n );
	void RotLeftY	( int n );
	void RotLeftZ	( int n );
	void RotRightX	( int n );
	void RotRightY	( int n );
	void RotRightZ	( int n );
};

void Dice::RotLeftX ( int n ) {
	int m[] = { 2, 1, 3 }; // f, bt, bk
	for(int i=0; i < n; ++i) {
		for(int j=0; j < 3; ++j) Swap(d[0], d[m[j]]); // t
	}
}
void Dice::RotLeftY ( int n ) {
	int m[] = { 2, 5, 3 }; // f, r, bk
	for(int i=0; i < n; ++i) {
		for(int j=0; j < 3; ++j) Swap(d[4], d[m[j]]); // l
	}
}
void Dice::RotLeftZ ( int n ) {
	int m[] = { 5, 0, 4 }; // r, t, l
	for(int i=0; i < n; ++i) {
		for(int j=0; j < 3; ++j) Swap(d[1], d[m[j]]); // bt
	}
}
void Dice::RotRightX ( int n ) {
	int m[] = { 3, 1, 2 }; // bk, bt, f
	for(int i=0; i < n; ++i) {
		for(int j=0; j < 3; ++j) Swap(d[0], d[m[j]]); // t
	}
}
void Dice::RotRightY ( int n ) {
	int m[] = { 3, 5, 2 }; // bk, r, f
	for(int i=0; i < n; ++i) {
		for(int j=0; j < 3; ++j) Swap(d[4], d[m[j]]); // l
	}
}
void Dice::RotRightZ ( int n ) {
	int m[] = { 4, 0, 5 }; // l, t, r
	for(int i=0; i < n; ++i) {
		for(int j=0; j < 3; ++j) Swap(d[1], d[m[j]]); // bt
	}
}

int main( void )
{
	int n;
	while(cin >> n, n) {
		string in;
		Dice dice(1, 6, 2, 5, 4, 3);
		int sum = 1;
		for(int i=0; i < n; ++i) {
			cin >> in;
			switch(in[0]) {
			case 'N':
				dice.RotRightX(1);
				break;
			case 'E':
				dice.RotRightZ(1);
				break;
			case 'W':
				dice.RotLeftZ(1);
				break;
			case 'S':
				dice.RotLeftX(1);
				break;
			case 'R':
				dice.RotRightY(1);
				break;
			case 'L':
				dice.RotLeftY(1);
				break;
			}
			sum += dice.Y.top;
		}
		cout << sum << endl;
	}
	return 0;
}
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct die_t {
	int top, front, right, left, back, bottom;

	die_t (int t, int f, int r, int l, int bk, int b)
		: top(t), front(f), right(r), left(l), back(bk), bottom(b) { }
	void rotate_swap ( int &a, int &b, int &c, int &d ) {
		swap(a, b); swap(b, c); swap(c, d);
	}
	void rotate_right( void ) { rotate_swap(top,left,bottom,right); }
	void rotate_left( void ) { rotate_swap(top,right,bottom,left); }
	void rotate_front( void ) { rotate_swap(top,back,bottom,front); }
	void rotate_back( void ) { rotate_swap(top,front,bottom,back); }
	void rotate_cw( void ) { rotate_swap(back,left,front,right); }
	void rotate_ccw( void ) { rotate_swap(back,right,front,left); }
};

int main ( void )
{
	int n;

	while (cin >> n, n) {
		die_t d(1, 2, 3, 4, 5, 6);
		int sum = 1;
		for (int i = 0; i < n; ++i) {
			string str;
			cin >> str;

			switch (str[0]) {
				case 'N': d.rotate_back(); break;
				case 'E': d.rotate_right(); break;
				case 'W': d.rotate_left(); break;
				case 'S': d.rotate_front(); break;
				case 'R': d.rotate_cw(); break;
				case 'L': d.rotate_ccw(); break;
			}

			sum += d.top;
		}

		cout << sum << endl;
	}
	return 0;
}
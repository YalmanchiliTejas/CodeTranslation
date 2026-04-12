#include <iostream>
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
	void rotate_left ( void ) { rotate_swap(top,right,bottom,left); }
	void rotate_front( void ) { rotate_swap(top,back,bottom,front); }
	void rotate_back ( void ) { rotate_swap(top,front,bottom,back); }
	void rotate_cw   ( void ) { rotate_swap(back,left,front,right); }
	void rotate_ccw  ( void ) { rotate_swap(back,right,front,left); }
};


int main(void) {
	int n;
	while (cin >> n, n) {
		cin.ignore();
		die_t die(1, 2, 3, 4, 5, 6);
		int cnt = 1;
		
		string str;
		for (int i = 0; i < n; i++) {
			getline(cin, str);
			if (str == "North")
				die.rotate_back();
			else if (str == "East")
				die.rotate_right();
			else if (str == "West")
				die.rotate_left();
			else if (str == "South")
				die.rotate_front();
			else if (str == "Right")
				die.rotate_cw();
			else if (str == "Left")
				die.rotate_ccw();
			cnt += die.top;
		}
		
		cout << cnt << endl;
	}
}
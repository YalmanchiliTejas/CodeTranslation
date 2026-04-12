#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void swap(int &a, int &b){
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

struct die_t {
public:
	int top, front, right, left, back, bottom;

	die_t (int t, int f, int r, int l, int bk, int b)
		: top(t), front(f), right(r), left(l), back(bk), bottom(b) { }

	void rotate_swap (int &a, int &b, int &c, int &d) {
		swap(a, b); swap(b, c); swap(c, d);
	}

	void rotate_right ( void ) { rotate_swap(top, left, bottom, right); }
	void rotate_left ( void ) { rotate_swap(top, right, bottom, left); }
	void rotate_front ( void ) { rotate_swap(top, back, bottom, front); }
	void rotate_back ( void ) { rotate_swap( top, front, bottom, back); }
	void rotate_cw ( void ) { rotate_swap(back, left, front, right); }
	void rotate_ccw ( void ) { rotate_swap(back, right, front, left); }
};

int main() {
	int n;

	while( true ) {
		cin >> n;

		if( !n ) {
			break;
		}

		vector< string > news(n);

		for(int i = 0; i < n; i++) {
			cin >> news[i];
		}

		struct die_t dice(1, 2, 3, 4, 5, 6);

		int ans = dice.top;

		for(int i = 0; i < n; i++) {
			if(news[i] == "North") {
				dice.rotate_back();
				ans += dice.top;
			} else if(news[i] == "East") {
				dice.rotate_right();
				ans += dice.top;
			} else if(news[i] == "West") {
				dice.rotate_left();
				ans += dice.top;
			} else if(news[i] == "South"){
				dice.rotate_front();
				ans += dice.top;
			} else if(news[i] == "Right") {
				dice.rotate_cw();
				ans += dice.top;
			} else if(news[i] == "Left") {
				dice.rotate_ccw();
				ans += dice.top;
			}
		}

		cout << ans << endl;

	}
}
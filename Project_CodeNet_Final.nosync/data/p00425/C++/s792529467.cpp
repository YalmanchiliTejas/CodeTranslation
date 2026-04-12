#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;


enum FACE { TOP, BOTTOM, FRONT, BACK, LEFT, RIGHT };

class dice {
private:
	int num[6];

	void roll(FACE a, FACE b, FACE c, FACE d) {
		int tmp = num[a];
		num[a] = num[b];
		num[b] = num[c];
		num[c] = num[d];
		num[d] = tmp;
	}

public:
	dice() {
		num[TOP] = 1;
		num[BOTTOM] = 6;
		num[FRONT] = 5;
		num[BACK] = 2;
		num[RIGHT] = 3;
		num[LEFT] = 4;
	}

	const int& operator[] (FACE f) const { return num[f]; }

	void north() { roll(TOP, BACK, BOTTOM, FRONT); }
	void east() { roll(TOP, LEFT, BOTTOM, RIGHT); }
	void west() { roll(TOP, RIGHT, BOTTOM, LEFT); }
	void south() { roll(TOP, FRONT, BOTTOM, BACK); }
	void right() { roll(BACK, RIGHT, FRONT, LEFT); }
	void left() { roll(BACK, LEFT, FRONT, RIGHT); }
};

int main() {
	cin.tie(false);
	ios::sync_with_stdio(false);

	for(int n; cin >> n, n;) {
		dice d;

		int ans = 1;
		for(int i = 0; i < n; ++i) {
			string ope;
			cin >> ope;

			switch(ope[0]) {
			case 'N':
				d.north();
				break;
			case 'E':
				d.east();
				break;
			case 'W':
				d.west();
				break;
			case 'S':
				d.south();
				break;
			case 'R':
				d.right();
				break;
			case 'L':
				d.left();
			}

			ans += d[TOP];
		}

		cout << ans << endl;
	}


	return EXIT_SUCCESS;
}
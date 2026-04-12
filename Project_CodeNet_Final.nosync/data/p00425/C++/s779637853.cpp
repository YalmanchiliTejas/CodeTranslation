#include<iostream>
using namespace std;

class Dice {
public:
	int t = 1, b = 6, n = 5, e = 3, s = 2, w = 4, tmp, sum = 1;
	void north() {
		tmp = t;
		t = s;
		s = b;
		b = n;
		n = tmp;
	}
	void east() {
		tmp = t;
		t = w;
		w = b;
		b = e;
		e = tmp;
	}
	void west() {
		tmp = t;
		t = e;
		e = b;
		b = w;
		w = tmp;
	}
	void south() {
		tmp = t;
		t = n;
		n = b;
		b = s;
		s = tmp;
	}
	void left() {
		tmp = s;
		s = w;
		w = n;
		n = e;
		e = tmp;
	}
	void right() {
		tmp = s;
		s = e;
		e = n;
		n = w;
		w = tmp;
	}
	void add() {
		sum += t;
	}

};

int main() {
	int i, j, n;
	char com[6];

	while (1) {
		cin >> n;
		if (n == 0)break;
		Dice d;
		for (i = 0; i < n; i++) {
			cin >> com;
			switch (com[0]) {
			case 'N':
				d.north();
				break;
			case 'E':
				d.east();
				break;
			case 'S':
				d.south();
				break;
			case 'W' :
				d.west();
				break;
			case 'R':
				d.right();
				break;
			case 'L':
				d.left();
				break;
			}
			d.add();
		}
		cout << d.sum << endl;
	}



	return 0;
}
#include <string>
#include <iostream>
using namespace std;


typedef struct Dice {
	int t, b, n, w, s, e;
}Dice;

Dice d = { 1,6,5,4,2,3 };
int n,sum;
string s;

int ini()
{
	d = { 1,6,5,4,2,3 };
	sum = 1;
	return 0;
}
int north() {
	int r = d.t;
	d.t = d.s;
	d.s = d.b;
	d.b = d.n;
	d.n = r;
	return 0;
}
int east() {
	int r = d.t;
	d.t = d.w;
	d.w = d.b;
	d.b = d.e;
	d.e = r;
	return 0;
}
int west() {
	int r = d.t;
	d.t = d.e;
	d.e = d.b;
	d.b = d.w;
	d.w = r;
	return 0;
}
int south() {
	int r = d.t;
	d.t = d.n;
	d.n = d.b;
	d.b = d.s;
	d.s = r;
	return 0;
}
int right() {
	int r = d.n;
	d.n = d.w;
	d.w = d.s;
	d.s = d.e;
	d.e = r;
	return 0;
}
int left() {
	int r = d.n;
	d.n = d.e;
	d.e = d.s;
	d.s = d.w;
	d.w = r;
	return 0;
}

int main(){
	while (cin >> n && n > 0) {
		ini();
		for (int i = 0; i < n; i++) {
			cin >> s;
			if (s == "North")
				north();
			else if (s == "West")
				west();
			else if (s == "South")
				south();
			else if (s == "East")
				east();
			else if (s == "Right")
				right();
			else if (s == "Left")
				left();
			sum += d.t;
		}
		cout << sum << endl;
	}

	return 0;
}
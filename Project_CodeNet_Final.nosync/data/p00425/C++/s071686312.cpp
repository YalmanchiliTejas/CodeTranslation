#include <iostream>
#include <string>
#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;

void north();
void south();
void west();
void east();
void right();
void left();

int top, bot, n, s, w, e, times, total, stock;
string inst;

int main() {
	while (cin >> times, times) {
		top = 1;
		bot = 6;
		n = 5;
		s = 2;
		w = 4;
		e = 3;
		total = 1; //initialize

		rep(i, times) {
			cin >> inst;
			if (inst == "North") north();
			if (inst == "South") south();
			if (inst == "West") west();
			if (inst == "East") east();
			if (inst == "Right") right();
			if (inst == "Left") left();
			total += top;
		}

		cout << total << endl;
	}

	return 0;
}

void north() {
	stock = top;
	top = s;
	s = bot;
	bot = n;
	n = stock;
	return;
}

void south() {
	stock = top;
	top = n;
	n = bot;
	bot = s;
	s = stock;
	return;
}

void west() {
	stock = top;
	top = e;
	e = bot;
	bot = w;
	w = stock;
	return;
}

void east() {
	stock = top;
	top = w;
	w = bot;
	bot = e;
	e = stock;
	return;
}

void right() {
	stock = n;
	n = w;
	w = s;
	s = e;
	e = stock;
	return;
}

void left() {
	stock = n;
	n = e;
	e = s;
	s = w;
	w = stock;
	return;
}
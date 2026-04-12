#include<iostream>
#include<string>
using namespace std;
int main() {
	int a,b,c,d,e,f,N,sum,g,i;
	string s;
	while (cin >> N) {
		if (N == 0)break;
		a = 1;
		b = 2;
		c = 3;
		d = 4;
		e = 5;
		f = 6;
		sum = 1;
		for (i = 0; i < N; i++) {
			cin >> s;
			if (s == "North") {
				g = a;
				a = b;
				b = f;
				f = e;
				e = g;
			}
			else if (s == "South") {
				g = a;
				a = e;
				e = f;
				f = b;
				b = g;
			}
			else if (s == "East") {
				g = a;
				a = d;
				d = f;
				f = c;
				c = g;
			}
			else if (s == "West") {
				g = a;
				a = c;
				c = f;
				f = d;
				d = g;
			}
			else if (s == "Left") {
				g = b;
				b = d;
				d = e;
				e = c;
				c = g;
			}
			else if (s == "Right") {
				g = b;
				b = c;
				c = e;
				e = d;
				d = g;
			}
			sum += a;
		}
		cout << sum << endl;
	}
	return 0;
}
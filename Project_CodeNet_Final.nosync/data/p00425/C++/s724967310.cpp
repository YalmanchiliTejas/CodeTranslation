#include<iostream>
#include<string>
using namespace std;
int main() {
	int n;
	while (cin >> n){
		if (n == 0)return 0;
		int    e;
		int d, a, c, f;
		int    b;
		//??????????±???????
		a = 1; b = 2; c = 3; d = 4; e = 5; f = 6;
		int sum = a;
		for (int i = 0; i < n; i++){
			string s;
			cin >> s;
			int tmp;
			if (s == "North") {
				tmp = a;
				a = b;
				b = f;
				f = e;
				e = tmp;
			}
			else if (s == "East") {
				tmp = a;
				a = d;
				d = f;
				f = c;
				c = tmp;
			}
			else if (s == "West") {
				tmp = a;
				a = c;
				c = f;
				f = d;
				d = tmp;
			}
			else if (s == "South") {
				tmp = a;
				a = e;
				e = f;
				f = b;
				b = tmp;
			}
			else if (s == "Right") {
				tmp = b;
				b = c;
				c = e;
				e = d;
				d = tmp;
			}
			else if (s == "Left") {
				tmp = b;
				b = d;
				d = e;
				e = c;
				c = tmp;
			}
			sum += a;
		}
		cout << sum << endl;
	}
}
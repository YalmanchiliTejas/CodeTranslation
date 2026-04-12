#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int parse(string a) {
	int b = 0;
	for (char c : a)b = b * 10 + c - 48;
	return b;
}
int main() {
	int a, b;
	while (cin >> a >> b, a | b) {
		bool c[1000]{};
		int sum = 0;
		int T = a;
		string p[10000]; getline(cin, p[0]);
		for (int i = 0; i < b; i++)getline(cin, p[i]);
		for (int d = 1; d <= b; d++,sum++) {
			while (c[sum%a])sum++;
			string k = p[d - 1];
			bool B = false;
			if (d % 3==0) {
				if (d % 5 == 0) {
					if (k != "FizzBuzz")B = true;
				 }
				else {
					if (k != "Fizz") B = true;
				}
			}
			else if (d % 5==0) {
				if (k != "Buzz")B = true;
			}
			else {
				if (parse(k) != d) B = true;
			}
			if (B) {
				T--;
				c[sum%a] = true;
			}
			if (T == 1)break;
		}
		int w = 0;
		for (int i = 0; i < a; i++) {
			if (!c[i]) {
				if (w)cout << " ";
				w++;
				cout << i + 1;
			}
		}
		cout << endl;
	}
}
#include<iostream>
#include<string>
#include<cmath>
#include<cstring>

using namespace std;

#define FIZZ 10000000
#define BUZZ 20000000
#define FIZZBUZZ 30000000

int x[100000], y[10000], n, m, num, turn, C, cnt, L; string S; char T[11] = "0123456789";
int main() {
	while (true) {
		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));
		num = 1; turn = 1; cnt = 0;
		cin >> n >> m; L = n;
		if (n == 0 && m == 0) { break; }
		for (int i = 1; i <= m; i++) { 
			cin >> S; 
			if (S == "Fizz") { x[i] = FIZZ; }
			else if (S == "Buzz") { x[i] = BUZZ; }
			else if (S == "FizzBuzz") { x[i] = FIZZBUZZ; }
			else if (S.size() >= 10) { x[i] = -1; }
			else {
				for (int j = 0; j < S.size(); j++) {
					for (int k = 0; k < 10; k++) {
						if (S[j] == T[k]) { x[i] += (int)pow(10, S.size() - j - 1)*k; goto E; }
					}
					x[i] = 0; goto F;
				E:;
				}
			F:;
			}
		}
		while (num <= m && L > 1) {
			if (y[turn] == 1) { goto G; }
			if (num % 15 == 0) { C = FIZZBUZZ; }
			else if (num % 5 == 0) { C = BUZZ; }
			else if (num % 3 == 0) { C = FIZZ; }
			else { C = num; }
			if (C != x[num]) { y[turn] = 1; L--; }
			num++;
		G:;
			turn++;
			if (turn > n) { turn -= n; }
		}
		for (int i = 1; i <= n; i++) {
			if (y[i] == 0) {
				if (cnt >= 1) { cout << ' '; }
				cout << i;
				cnt++;
			}
		}
		cout << endl;
	}
}
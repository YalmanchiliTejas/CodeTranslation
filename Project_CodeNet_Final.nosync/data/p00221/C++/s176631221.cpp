#include"bits/stdc++.h"
using namespace std;
int main() {
	int n, m, j, suu;
	while ((cin >> m >> n) && m != 0 || n != 0) {
		int check[1001] = { 0 };
		for (int i = 1; i <= m; i++)check[i] = i;
		j = 1;
		suu = m;
		for (int i = 1; i <= n; i++) {
			string str;

			cin >> str;
			if (suu > 1) {
				if (i % 15 == 0) {
					if (str != "FizzBuzz") {
						check[j] = 0;
						suu--;
					}
				}
				else if (i % 3 == 0) {
					if (str != "Fizz") {
						check[j] = 0;
						suu--;
					}
				}
				else if (i % 5 == 0) {
					if (str != "Buzz") {
						check[j] = 0;
						suu--;
					}
				}
				else {
					char buf[10] = { NULL };
					sprintf(buf, "%d", i);
					if (str != buf) {
						check[j] = 0;
						suu--;
					}
				}
				//j++;
				/*int x;
					for (x = j; check[x] == 0;) {
						x++;
						if (x > m)x = 1;
					}
				j = x;*/
				int j2 = j;
				for (int x = j+1; x <= m; x++) {
					if (check[x] != 0) {
						j2 = x; break;
					}
				}
				if (j == j2)for (int x = 1; x < j; x++) {
					if (check[x] != 0) {
						j2 = x; break;
					}
				}
				j = j2;
			}
		}
		int las;
		for (int i = m; i > 0; i--) if (check[i] != 0) {
			las = i; break;
		}
		for (int i = 1; i <= m; i++)
		{
			if (check[i] != 0)
			{
				cout << i;
				if (i<las)
					cout << " ";
			}
		}
		cout << endl;
	}
}
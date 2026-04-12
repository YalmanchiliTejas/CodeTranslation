#include<iostream>
#include<algorithm>
#include<queue>
#include<deque>
#include<vector>
#include<cstring>
using namespace std;
long long modpow(long long a, long long n, long long mod);
long long modinv(long long a, long long mod);
int main() {

	//A

	int n;
	cin >> n;
	if (n >= 30) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;

	//B
	/*int n;
	int i;
	int counter = 0;
	long long int x, y;
	long long int d;
	cin >> n >> d;
	for (i = 0; i < n; i++) {
		cin >> x >> y;
		if (x * x + y * y <= d * d)counter++;
	}
	cout << counter << endl;
	return 0;
	*/
	//C
	/*int k;
	cin >> k;
	
	if (7 % k == 0) {
		cout << 1 << endl;
		return 0;
	}
	if (k % 7 == 0)k = k / 7;
	if (k % 2 == 0 || k % 5 == 0) {
		cout << -1 << endl;
		return 0;
	}
	if (k == 3) {
		cout << 3 << endl;
		return 0;
	}
	else if (k == 9) {
		cout << 9 << endl;
		return 0;
	}
	
	
	int i = 0;
	int j = 1;
	while (1) {
		i++;
		j = j * 10;
		j = j % k;
		if (j == 1) {
			if (k % 9 == 0) {
				i = i * 9;
			}
			else if (k % 3 == 0) {
				i = i * 3;
			}
			cout << i << endl;
			return 0;
		}

	}*/

	//D
	/*int n;
	string c;
	cin >> n;
	cin >> c;
	int sum = 0;
	int i, j;
	int s = 0;
	i = 0; j = n - 1;
	while (i < j) {
		if (c[i] == 'W') {
			if (c[j] == 'R') {
				c[i] = 'R';
				c[j] = 'W';
				i++;
				j--;
				sum++;
			}
			else {
				while (c[j] != 'R') {
					j--;
					if (j < 0 || j <= i) {
						cout << sum << endl;
						return 0;
					}
				}
				c[i] = 'R';
				c[j] = 'W';
				i++;
				j--;
				sum++;
			}
		}
		else {
			while (c[i] != 'W') {
				i++;
				if (i >= n || i >= j) {
					cout << sum << endl;
					return 0;
				}
			}
			if (c[j] == 'R') {
				c[i] = 'R';
				c[j] = 'W';
				i++;
				j--;
				sum++;
			}
			else {
				while (c[j] != 'R') {
					j--;
					if (j < 0 || j <= i) {
						cout << sum << endl;
						return 0;
					}
				}
				c[i] = 'R';
				c[j] = 'W';
				i++;
				j--;
				sum++;
			}
		}
	}

	cout << sum << endl;
	return 0;	
	*/
}

// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
	long long res = 1;
	while (n > 0) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

// a^{-1} mod を計算する
long long modinv(long long a, long long mod) {
	return modpow(a, mod - 2, mod);
}

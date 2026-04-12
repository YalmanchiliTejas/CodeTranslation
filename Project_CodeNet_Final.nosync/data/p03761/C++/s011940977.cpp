
#include "bits/stdc++.h"
using namespace std;
/*第二引数で第一引数を割ったときの切り上げの計算*/
long long int maxtime(long long int x, long long int y) {
	return(x + y - 1) / y;

}
/*最大公約数*/
long long int lcm(long long int number1, long long int number2) {
	long long int m = number1;
	long long int n = number2;

	if (number2 > number1) {
		m = number2;
		n = number1;
	}
	long long int s = -1;
	while (s != 0) {
		s = m % n;
		m = n;
		n = s;
	}
	return m;
}
/*最大公倍数*/
long long int gcd(long long int number1, long long int number2) {
	long long int m = number1;
	long long int n = number2;
	return m / lcm(m, n) * n;
}
int main() {
	int n;
	cin >> n;
	string s;
	string arfa = "abcdefghijklmnopqrstuvwxyz";
	map<char, int> c;
	for (int i = 0; i < arfa.size(); i++) {
		c[arfa[i]] = 100;
	}

	for (int i = 0; i < n; i++) {
		string k;
		cin >> k;
		map<char, int>ans;
		for (int j = 0; j < k.size(); j++) {
			ans[k[j]]++;
		}
		for (int j = 0; j < arfa.size(); j++) {
			if (c[arfa[j]] > ans[arfa[j]]) {
				c[arfa[j]] = ans[arfa[j]];
			}
		}
	}
	string kotae = "";
	for (int i = 0; i < arfa.size(); i++) {
		for (int j = 0; j < c[arfa[i]]; j++) {
			kotae = kotae + arfa[i];
		}
	}
	cout << kotae;
}
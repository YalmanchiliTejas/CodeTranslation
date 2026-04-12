#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <functional>
using namespace std;

//素数判定
inline bool IsPrime(int p) {
	if (p == 1) return false;
	for (int i = 2; i <= sqrt(p); i++) {
		if (p%i == 0) return false;
	}
	return true;
}

//10進数の自然数の桁数を返す
inline int GetDigit(int num) {
	return (int)log10(num) + 1;
}

//各位の和を返す
int GetDigitsSum(int num) {
	int N = 0;
	while (num > 0) {
		N += num % 10;
		num /= 10;
	}
	return N;
}

int main() {
	int N;
	cin >> N;

	if (N == 7 || N == 5 || N == 3) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}

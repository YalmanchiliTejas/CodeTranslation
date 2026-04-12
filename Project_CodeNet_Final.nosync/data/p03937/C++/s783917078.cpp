#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
typedef long long ll;
using namespace std;
//#define int long long

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

//互除法
ll gcd(ll a, ll b) {
	if (a < b) {
		return gcd(b, a);
	}
	else if (a%b) {
		return gcd(b, a%b);
	}
	else {
		return b;
	}
}

//最小公倍数
ll lcm(ll a, ll b) {
	ll g = gcd(a, b);
	return a / g * b; // Be careful not to overflow

}

//異なるn個からr個の整数を取り出す組合せの数を求める
int combination(int n, int r) {
	if (r == 0 || n == r) {
		return 1;
	}
	else if (r == 1) {
		return n;
	}
	else {
		return combination(n - 1, r - 1) + combination(n - 1, r);
	}

}

//Ｏ(√n)
//素因数分解
map<int, int> prime_factor(int n) {
	map<int, int> res; // map[i]:=ｎを素因数分解したときiは何乗か。
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			while (n % i == 0) {
				res[i]++;
				n /= i;
			}
		}
	}
	if (n != 1)
		res[n] = 1;
	return res;
}

//Ｏ(√n)
//素因数分解
map<int, int> prime_factor_ver2(int n, map<int, int> res) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			while (n % i == 0) {
				res[i]++;
				n /= i;
			}
		}
	}
	if (n != 1)
		res[n]++;
	return res;
}


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int H, W;
	int cnt = 0;
	cin >> H >> W;

	for (int i = 0; i < H; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < W; j++)
		{
			if (s[j] == '#') {
				cnt++;
			}
		}
	}

	if (H + W - 1 == cnt) {
		cout << "Possible" << endl;
	}
	else {
		cout << "Impossible" << endl;
	}

	return 0;
}

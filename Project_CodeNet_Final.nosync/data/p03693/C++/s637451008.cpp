#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<cstdlib>
#include<map>
#include<fstream>
#include<string>
#include<sstream>
#include<iomanip>
#include<cmath>
#include<random>
#include<set>
#include<queue>

using namespace std;

long long dp[3][100100] = {};
const long long INF = 1LL << 60;
#define MOD 1000000007
#define Int int64_t
#define PI 3.14159265358979
#define dump(a) cout << a << endl; 

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

/**
* @fn
* 最大値を取ります.Vector<int>を渡すこと.
*/
long long int imax(vector<int> a) {
	int MAX = -10000000;
	for (int i = 0; i < a.size(); i++) {
		if (MAX < a.at(i)) MAX = a.at(i);
	}
	return MAX;
}

/**
* @fn
* 最小値を取ります.Vector<int>を渡すこと.
*/
long long int imin(vector<int> a) {
	int MIN = 1000000000;
	for (int i = 0; i < a.size(); i++) {
		if (MIN > a.at(i)) MIN = a.at(i);
	}
	return MIN;
}

/**
* @fn
* 自然数について、桁数を求める
*/
Int getDigit(Int num) {
	return (Int)(log10(num)) + 1;
}


int get2Digit(Int num) {
	int cnt = 0;
	while (num > 0) {
		if (num % 2 != 0) {
			return cnt;
		}
		cnt++;
		num /= 2;
	}
}

long long int absmin(vector<int> a, long long int b) {
	int mini = 100000000;
	int d = 0;
	for (int i = 0; i < a.size(); i++) {
		if (mini > abs(a.at(i) - b)) {
			mini = abs(a.at(i) - b);
			d = i;
		}
	}
	return d;
}


long long int absmax(vector<int> a, long long int b) {
	int max = -100000000;
	int d = 0;
	for (int i = 0; i < a.size(); i++) {
		if (max < abs(a.at(i) - b)) {
			max = abs(a.at(i) - b);
			d = i;
		}
	}
	return d;
}

int gcd(int a, int b)
{
	if (a < b) swap(a, b);
	if (b < 1) return -1;
	if (a % b == 0) return b;
	return gcd(b, a % b);
}

void haerobatya(int start, int end, char level) {
	if (start > end) swap(start, end);
	for (int i = start; i <= end; i++) {
		if (i < 100) {
			cout << "https://atcoder.jp/contests/abc0" << i << "/tasks/abc0" << i << "_" << level << endl;
		}
		else {
			cout << "https://atcoder.jp/contests/abc" << i << "/tasks/abc" << i << "_" << level << endl;
		}
	}
}

long long int cntmod(long long int warareru, long long int mod) {
	long long int i = 0;
	for (i = 0; true; i++) {
		if (warareru % mod == 0 && warareru >= mod) {
			warareru /= mod;
		}
		else {
			return i;
		}
	}
}

void ansYes(bool a) {
	if (a == true) cout << "Yes" << endl;
	else cout << "No" << endl;
}

void ansYES(bool a) {
	if (a == true) cout << "YES" << endl;
	else cout << "NO" << endl;
}


Int euclidean_gcd(Int a, Int b) {
	while (true) {
		if (a < b) swap(a, b);
		if (!b) break;
		a %= b;
	}
	return a;
}

typedef pair<int, int> pai;


//ここまでライブラリ
//ここから本文
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	ansYES((a * 100 + b * 10 + c) % 4 == 0);
}
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <limits>
#include <numeric>
#include <queue>
#include <set>
#include <bitset>
#include <map>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef queue<int, int> qii;
typedef pair<int, int> pii;

#define PI 3.14159265359
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repz(i,n) rep(i,0,n)

//int型を受け取ってその桁数を返す
int check_digits(int n) {
	int digits = 0;
	while (n != 0) {
		n /= 10;
		digits++;
	}
	return digits;
}

//int型を受け取ってその各桁の和を返す
int sum_digits(int n) {
	int sum=0;
	int N = n;
	while (N) {
		sum += N % 10;
		N /= 10;
	}
	return sum;
}


//最大公約数を返す関数
int gcd(int n, int m) {
	while (n != 0) {
		if (n < m) swap(n, m);
		n = n % m;
	}
	return m;
}


//2点間の距離を返す
float dis(int x1, int y1, int x2, int y2) {
	return sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));
}


int main() {
	int n, w;
	cin >> n >> w;
	vector<vector<char>> rap(n ,vector<char>(w));
	vi memo_n(n+1,0);
	vi memo_w(w+1,0);
	repz(i, n) {
		repz(j, w) {
			cin >> rap[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for(int j = 0;j < w; ++j) {
			if (rap[i][j] == '#')break;
			if (j == (w - 1))memo_n[i] = 1;
		}
	}

	for (int i = 0; i < w; i++) {
		for (int j = 0; j < n; ++j) {
			if (rap[j][i] == '#')break;
			if (j == (n - 1))memo_w[i] = 1;
		}
	}

	repz(i, n) {
		repz(j, w) {
			if (memo_n[i] == 0 && memo_w[j] == 0)cout << rap[i][j];
			if (j == w - 1 && memo_n[i] == 0)cout << endl;
		}
	}

	system("pause");
	return 0;
}
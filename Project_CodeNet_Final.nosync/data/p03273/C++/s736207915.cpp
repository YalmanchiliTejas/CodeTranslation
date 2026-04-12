#include<iostream>
#include<array>
#include<vector>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <utility>
#include <set>

using llint = long long int;
using namespace std;

namespace CsF {
#define MIN_INT -2147483648
#define MAX_INT 2147483647

#define nfor(I,J,K) for(int I = 0;I < J;I+=K)


	string ConvertBit(int N, int e) {
		string s = "";
		int r = 0;
		while (N != 0) {
			r = N % e;
			s = to_string(r) + s;
			N -= r;
			N /= e;
		}
		return s;
	}

	int GCD(int a, int b) {
		if (a < b)swap(a, b);
		int r = a % b;
		while (r != 0) {
			a = b;
			b = r;
			r = a % b;
		}
		return b;
	}

	int LCM(int a, int b) {
		int n = a * b;
		return (n / GCD(a, b));
	}

	int Count(string s, char c) {
		int cou = 0;
		nfor(i, s.length(), 1) {
			if (s[i] == c)cou++;
		}
		return cou;
	}
}

using namespace CsF;


int main() {
	int H, W;
	cin >> H >> W;
	string s[100];
	bool w[100];
	bool h[100];
	nfor(i, H, 1) {
		cin >> s[i];
	}
	nfor(i, H, 1) {
		if (s[i][0] == '.' && Count(s[i], s[i][0]) == W) {
			h[i] = false;
		}
		else h[i] = true;
	}
	bool flag = true;
	nfor(i, W, 1) {
		if (s[0][i] == '#') {
			w[i] = true;
			continue;
		}
		flag = true;
		nfor(j, H, 1) {
			if (s[0][i] != s[j][i]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			w[i] = false;
		}
		else w[i] = true;
	}
	bool write = false;
	nfor(i, H, 1) {
		if (!h[i])continue;
		write = false;
		nfor(j, W, 1) {
			if (h[i] && w[j]) {
				cout << s[i][j];
				write = true;
			}
		}
		if (write)cout << endl;
	}

	return 0;
}

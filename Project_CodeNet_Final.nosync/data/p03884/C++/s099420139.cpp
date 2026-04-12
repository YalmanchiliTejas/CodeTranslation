#include <bits/stdc++.h>
#define mod 1000000007
#define mod998 998244353
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define mkp make_pair
typedef long long ll;
using namespace std;

const string FES = "FESTIVA";
string S;
ll K;

int main() {
	cin >> K;
	for (int i = 0; i < 60; ++i) {
		if (i == 0) {
			S = FES;
		}
		else if (i <= 7) {
			S += FES.substr(7 - i);
		}
		else if (i <= 15) {
			for (int j = 0; j < (1 << i - 7); ++j) {
				S.push_back('F');
			}
			S += FES.substr(1);
		}
		else if (i <= 23) {
			for (int j = 0; j < (1 << i - 15); ++j) {
				S.push_back('E');
			}
			S += FES.substr(2);
		}
		else if (i <= 31) {
			for (int j = 0; j < (1 << i - 23); ++j) {
				S.push_back('S');
			}
			S += FES.substr(3);
		}
		else if (i <= 39) {
			for (int j = 0; j < (1 << i - 31); ++j) {
				S.push_back('T');
			}
			S += FES.substr(4);
		}
		else if (i <= 47) {
			for (int j = 0; j < (1 << i - 39); ++j) {
				S.push_back('I');
			}
			S += FES.substr(5);
		}
		else if (i <= 55) {
			for (int j = 0; j < (1 << i - 47); ++j) {
				S.push_back('V');
			}
			S += FES.substr(6);
		}
		else {
			for (int j = 0; j < (1 << i - 55); ++j) {
				S.push_back('A');
			}
		}
		if ((1ll << i)&K) {
			S.push_back('L');
		}
	}
	cout << S << endl;
}
#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	cin >> N;
	bool a = false, b = false;
	int anum = 0;
	bool add = true;
	int box = 0;
	for (auto i : s) {
		if (i == '+') {
			add = true;
			anum += box;
			box = 0;
		}
		else if (i == '*') {
			add = false;
		}
		else {
			if (add) {
				box += i - '0';
			}
			else {
				box *= i - '0';
			}
		}
	}
	anum += box;
	if (anum == N)a = true;
	int bnum = 0;
	add = true;
	for (auto i : s) {
		if (i == '+')add = true;
		else if (i == '*')add = false;
		else {
			if (add) {
				bnum += i - '0';
			}
			else {
				bnum *= i - '0';
			}
		}
	}
	if (bnum == N)b = true;
	if (a&&b)cout << "U" << endl;
	else if (a)cout << "M" << endl;
	else if (b)cout << "L" << endl;
	else cout << "I" << endl;
}

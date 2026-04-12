#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<functional>
#include<map>
#include<cstdlib>
#include<complex>
#include<numeric>
#include<set>
#include<deque>
#include<queue>

using namespace std;
using Int = long long;
Int INF = 1LL << 60;
const Int MOD = 1000000000 + 7;

template <class T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
	for (const auto& e : vec) os << e << (&e == &vec.back() ? "\n" : " ");
	return os;
}
template <class T>
ostream& operator<<(ostream& os, const set<T>& st) {
	for (const auto& e : st) os << e << " ";
	return os;
}
template <class T1, class T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
	os << "(" << p.first << "," << p.second << ")";
	return os;
}
template <class T1, class T2>
ostream& operator<<(ostream& os, const map<T1, T2>& mp) {
	for (const auto& e : mp) os << e << " ";
	return os;
}

#ifdef _DEBUG
template <class T>
void dump(const char* str, T&& h) { cerr << str << " = " << h << "\n"; };
template <class Head, class... Tail>
void dump(const char* str, Head&& h, Tail&&... t) {
	while (*str != ',') cerr << *str++; cerr << " = " << h << "\n";
	dump(str + (*(str + 1) == ' ' ? 2 : 1), t...);
}
#define DMP(...) dump(#__VA_ARGS__, __VA_ARGS__)
#else 
#define DMP(...) ((void)0)
#endif

int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Int H, W;
	cin >> H >> W;

	vector<vector<Int>> a(H, vector<Int>(W));
	char temp;
	for (Int i = 0; i < H; i++) {
		for (Int j = 0; j < W; j++) {
			cin >> temp;
			if (temp=='#') {
				a[i][j] = 1;
			}
		}
	}

	//横方向
	vector<Int> yoko(H);
	Int flag;
	for (Int i = 0; i < H; i++) {
		flag = 0;
		for (Int j = 0; j < W; j++) {
			if (a[i][j]) {
				flag = 1;
				yoko[i] = 1;
				break;
			}
		}
	}

	vector<Int> tate(W);
	for (Int j = 0; j < W; j++) {
		for (Int i = 0; i < H; i++) {
			flag = 0;
			if (a[i][j]) {
				flag = 1;
				tate[j] = 1;
				break;
			}
		}
	}

	DMP(yoko, tate);

	for (Int i = 0; i < H; i++) {
		for (Int j = 0; j < W; j++) {
			if (yoko[i]&&tate[j]) {
				if (a[i][j]) {
					cout  << "#";
				}
				else {
					cout << ".";
				}
			}
		}
		if (yoko[i]) {
			cout << "\n";
		}

	}
}

#include <bits/stdc++.h>
struct fastio{fastio(){std::ios::sync_with_stdio(false);std::cin.tie(nullptr);}}_fast_io_;
template<class T> bool chmin (T &a, const T &b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> bool chmax (T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }

int main() {
	int x;
	std::cin >> x;
	if (x >= 30) std::cout << "Yes" << '\n';
	else std::cout << "No" << '\n';
	return 0;
}
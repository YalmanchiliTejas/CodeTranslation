#ifdef __GNUC__
#pragma GCC target("avx2")
#pragma GCC optimize ("O20")
#pragma GCC optimize ("tree-vectorize")
#pragma GCC optimize("unroll-loops")
#define iss std::cin
#endif
#include "bits/stdc++.h"
#define rep(i, times) for(ll i = 0; i < (times); ++i)
#define p(x) (cout << x << "\n")
using ll = int_fast64_t; using namespace std;

#ifndef __GNUC__
string text =
R"X(1500 2000 500 90000 100000)X";
stringstream iss{text};
#endif

int main( ) {
	cin.tie(0);	ios::sync_with_stdio(0);
	ll A, B, C, X, Y; iss >> A >> B >> C >> X >> Y;
	ll bXY = max(X, Y) * 2 + 1;
	ll price{LLONG_MAX};
	rep(c, bXY) {
		ll a = max(X - c / 2, 0l);
		ll b = max(Y - c / 2, 0l);
		price = min(price, a * A + b * B + c * C);
	}
	p(price);
}
#include <bits/stdc++.h>

using namespace std;
using lli = int_fast64_t;
using ulli = uint_fast64_t;
#define debug(x) cerr << #x << " : " << x << endl
#define debugv(x) cerr << #x << " : {";for(auto value_of_x:x){ cerr << value_of_x << ", ";}cerr << endl
#define debugst(x) auto xt = x;cerr << #x << " : {";for(int i=0;i<x.size();i++){ cerr << xt.top() << ", ";xt.pop();}cerr << endl
#define debugvp(x) cerr << #x << " : {";for(auto value_of_x:x){ cerr << value_of_x.first << " : " << value_of_x.second << ", ";}cerr << endl
#define HYPP(x) hypot(x.first,x.second)

const lli MOD = 1000000007;
const lli LIMIT = 1000000000000000000 * 5;
const int tenfive = 100000;



int main() {
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	C *= 2;
	int ans = 0;
	if (X > Y) {
		swap(X, Y);
		swap(A, B);
	}
	if (A > C || B > C || A+B > C) {
		ans += C * X;
		Y -= X;
	}
	else {
		ans += A * X;
	}
	if (B > C) {
		ans += C * Y;
	}
	else {
		ans += B * Y;
	}
	cout << ans << endl;
	return 0;
}

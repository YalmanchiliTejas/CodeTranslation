#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {
	void Solve() {
		UL a, b; a = b = 0;
		rep(i, 3) {
			char c; cin >> c;
			if (c == 'A') a++; else b++;
		}
		cout << ((a && b) ? "Yes" : "No") << endl;
	}

	Problem();
};
int main() {
	unique_ptr<Problem> p(new Problem());
	p->Solve();
	return 0;
}
Problem::Problem() {
	cout << fixed << setprecision(10);
}
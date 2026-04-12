#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)


struct Problem {

	void Solve() {
		UL a, b; cin >> a >> b;
		
		if (a == b) cout << "Yes" << endl;
		else cout << "No" << endl;
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

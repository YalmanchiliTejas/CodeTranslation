#include <iostream>
using namespace std;
using Int = long long;
Int a(Int n) { return (1LL << (n + 2)) - 3; }
Int p(Int n) { return (1LL << (n + 1)) - 1; }
Int f(Int N, Int X) {
	if (N == 0) return X > 0;
	else if (X <= 1 + a(N - 1)) return f(N - 1, X - 1);
	return p(N - 1) + 1 + f(N - 1, X - 2 - a(N - 1));
}
int main() {
	Int N, X;
	cin >> N >> X;
	cout << f(N, X) << endl;
}

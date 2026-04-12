#include <bits/stdc++.h>
using namespace std;

using intBil7 = unsigned int;
class modBil7 {
private:
	static const intBil7 bil7 = 1000000007;
	vector<intBil7> fact;
	vector<intBil7> invfact;
public:
	intBil7 add(intBil7 a, intBil7 b) { return (a + b) % 1000000007; }
	intBil7 sub(intBil7 a, intBil7 b) { return (a + (bil7 - b)) % 1000000007; }
	intBil7 mul(intBil7 a, intBil7 b) { return (intBil7)((unsigned long long)a * (unsigned long long)b % (unsigned long long)bil7); }
	intBil7 div1(intBil7 b) {
		stack<pair<intBil7, pair<int, int>>> divbuf;
		intBil7 buf = bil7;
		while (b != 0) { divbuf.push(make_pair(buf / b, make_pair(buf, b))); buf %= b; swap(b, buf); }
		pair<int, int> m = make_pair(buf, buf);
		while (!divbuf.empty()) {
			m.second = sub(m.second, mul(m.first, divbuf.top().first));
			divbuf.pop(); swap(m.first, m.second);
		}
		return m.first;
	}
	intBil7 div(intBil7 a, intBil7 b) { return mul(div1(b), a); }
	intBil7 factorial(unsigned int a) {
		if (fact.empty()) fact.push_back(1);
		if (a >= bil7) return mul(factorial(bil7 - 1), a - bil7);
		for (int i = fact.size(); i <= a; i++) {
			fact.push_back(mul(fact.back(), i));
		}
		return fact[a];
	}
	intBil7 ifactorial(unsigned int a) { return div1(factorial(a)); }
	intBil7 C(unsigned int n, unsigned int m) {
		return mul(mul(factorial(n), ifactorial(n - m)), ifactorial(m));
	}
};

int main() {
	intBil7 n, m, k;
	cin >> n >> m >> k;
	modBil7 bil7;

	int N =
		bil7.mul(
			bil7.mul(n, n),
			bil7.div(bil7.mul(bil7.mul(m, m - 1), m + 1), 6));
	int M =
		bil7.mul(
			bil7.mul(m, m),
			bil7.div(bil7.mul(bil7.mul(n, n-1), n + 1), 6));
	int C = bil7.C( bil7.sub(bil7.mul(m, n), 2), bil7.sub(k, 2));

	cout << bil7.mul(bil7.add(N, M), C) << endl;
	return 0;
}

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repr(i, n) for(int i = ((int)(n) - 1); i >= 0; i--)
#define repn(i, n) for(int i = 1; i <= (int)(n); i++)
#define reprn(i, n) for(int i = ((int)(n)); i > 0; i--)
#define all(x) (x).begin(), (x).end()
using llint = long long int;
using lint = long int;

#include <iostream>
#include <array>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
	int n, k;
	string s;
	cin >> n >> s >> k;
	auto star = s[k - 1];
	rep(i, s.length()) {
		if (s[i] != star) {
			s[i] = '*';
		}
	}
	cout << s << endl;
	return 0;
}

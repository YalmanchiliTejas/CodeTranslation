#include <bits/stdc++.h>
#define mod 1000000007
#define mod998 998244353
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define mkp make_pair
typedef long long ll;
using namespace std;
const string nyan("(=^・ω・^=)");

int N, c, H, MAX;

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> H;
		if (MAX <= H) {
			++c;
			MAX = H;
		}
	}
	cout << c << endl;
}
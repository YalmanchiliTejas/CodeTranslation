#include <bits/stdc++.h>
#define mod 1000000007
#define mod998 998244353
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define mkp make_pair
typedef long long ll;
using namespace std;

int N, s[100000], t[100000];
ll res;

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> s[i];
	}
	for (int i = 0; i < N; ++i) {
		t[i] = s[i] + s[N - i - 1];
	}
	for (int i = 1; i < N; ++i) {
		ll s = 0;
		for (int j = 0; j < N; j += i) {
			s += t[j];
			if (j < N / 2)res = max(res, s);
			else {
				int a = N - 1 - j;
				if (a < i)break;
				if (a%i) {
					res = max(res, s);
				}
			}
		}
	}
	cout << res << endl;
}
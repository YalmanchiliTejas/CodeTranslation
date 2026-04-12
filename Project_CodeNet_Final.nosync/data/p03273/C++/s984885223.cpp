#include <bits/stdc++.h>
#define sp ' '
#define nyan "(=^・ω・^=)"
#define mkp make_pair
#define intmax 2147483647
#define llmax 9223372036854775807
#define lP pair<ll,ll>
#define iP pair<int,int>
typedef long long ll;
using namespace std;
const int mod = 1000000007, mod998 = 998244353;

int H, W;
bool h[100], w[100];
char a[100][100];

int main() {
	cin >> H >> W;
	for (int i = 0; i != H; ++i) {
		for (int j = 0; j != W; ++j) {
			cin >> a[i][j];
			if (a[i][j] == '#') {
				h[i] = w[j] = true;
			}
		}
	}
	for (int i = 0; i != H; ++i) {
		if (h[i]) {
			for (int j = 0; j != W; ++j) {
				if (w[j]) {
					cout << a[i][j];
				}
			}
			cout << endl;
		}
	}
	return 0;
}
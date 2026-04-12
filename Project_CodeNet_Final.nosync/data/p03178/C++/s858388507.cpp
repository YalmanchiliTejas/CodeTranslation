#include <bits/stdc++.h>
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define nyan "(=^･ω･^=)"
#define mkp make_pair
#define lP pair<ll, ll>
#define iP pair<int,int>
typedef long long ll;
using namespace std;

string K;
vector<int>s;
ll DP[100][2], res;
int D;

int main() {
	cin >> K >> D;
	s.push_back(0);
	for (int i = 0; i != K.size(); ++i)
		s.push_back(s[i] + K[i] - '0');
	DP[0][0] = DP[0][1] = 1;
	res = mod;
	--res;
	++s.back();
	for (int i = K.size(); i; --i) {
		for (int j = s[i - 1]; j != s[i]; ++j) {
			res += DP[(D - j%D) % D][i & 1];
			res %= mod;
		}
		for (int j = 0; j != D; ++j) {
			DP[j][(i - 1) & 1] = 0;
			for (int k = 0; k != 10; ++k) {
				DP[j][(i - 1) & 1] += DP[(D + j - (k%D)) % D][i & 1];
				DP[j][(i - 1) & 1] %= mod;
			}
		}
	}
	cout << res << endl;
	return 0;
}
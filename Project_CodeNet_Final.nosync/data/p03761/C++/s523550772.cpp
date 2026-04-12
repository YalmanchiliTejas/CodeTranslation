#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<functional>
#include<map>
#include<cstdlib>
#include<complex>
#include<numeric>
#include<set>
#include<deque>

using namespace std;
using Int = long long;
Int INF = 1LL << 60;
const Int MOD = 1000000000 + 7;

int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Int N;
	cin >> N;

	vector<string> s(N);
	for (Int i = 0; i < N; i++) {
		cin >> s[i];
	}

	char temp;
	vector<vector<Int>> al(N, vector<Int>(26, 0));

	Int len;
	for (Int i = 0; i < N; i++) {
		len = s[i].size();
		for (Int j = 0; j < len; j++) {
			al[i][s[i][j] - 'a']++;
		}
	}

	vector<Int> ans(26, INF);
	for (Int i = 0; i < N; i++) {
		for (Int j = 0; j < 26; j++) {
			ans[j] = min(ans[j], al[i][j]);
		}
	}

	for (Int i = 0; i < 26; i++) {
		for (Int j = 0; j < ans[i]; j++) {
			printf("%c", i + 'a');
		}
	}
	printf("\n");
}
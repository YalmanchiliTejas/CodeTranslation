#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// int A, B, F, H, I, J, K, L, M, N, S, T, U;
// long long int A, B, F, H, I, J, K, L, M, N, S, T, U;
string S, T, U;
int A, B;
string ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> S;

	if (S == "AAA" || S == "BBB")
		ans = "No";
	else
		ans = "Yes";

	cout << ans << endl;
	return 0;
}
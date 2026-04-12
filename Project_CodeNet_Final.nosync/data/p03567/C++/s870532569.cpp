#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "iomanip"
#include "cmath"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	for (int i = 0; i < s.size() - 1; i++) {
		if (s[i] == 'A'&&s[i + 1] == 'C') {
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
	return 0;
}

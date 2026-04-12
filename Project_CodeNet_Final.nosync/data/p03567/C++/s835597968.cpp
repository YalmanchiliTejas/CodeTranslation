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

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	N = s.size() - 1;
	for (int i = 0; i < N; i++) {
		if (s[i] == 'A'&&s[i + 1] == 'C') {
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
	return 0;
}
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
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "functional"

using namespace std;

//constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<long long int>num;
	num.push_back(1);
	long long int box = 1;
	int c = 8;
	int p = 1;
	while (box < N / 100) {
		box *= c;
		box /= p;
		c++;
		p++;
		num.push_back(box);
	}
	reverse(num.begin(), num.end());
	string ans;
	for (int i = 0; i < num.size(); i++) {
		for (int j = 0; j < N / num[i]; j++)ans.push_back('F');
		ans += "ESTIVAL";
		N %= num[i];
	}
	cout << ans << endl;
}

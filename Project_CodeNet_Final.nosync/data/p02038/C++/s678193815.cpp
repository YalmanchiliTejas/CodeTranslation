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

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	char ans = 'a';
	for (int i = 0; i < N; i++){
		char a;
		cin >> a;
		if (ans == 'a') {
			ans = a;
			continue;
		}
		if (ans == 'F')ans = 'T';
		else ans = a;
	}
	cout << ans << endl;
	return 0;
}


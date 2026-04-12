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

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> H >> W;
	vector<string>s(H);
	for (int i = 0; i < H; i++)cin >> s[i];
	vector<int>w(W);
	vector<int>h(H);
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (s[i][j] == '#') {
				w[j]++, h[i]++;
			}
		}
	}
	for (int i = 0; i < H; i++) {
		bool f = false;
		for (int j = 0; j < W; j++) {
			if (h[i] && w[j]) {
				cout << s[i][j];
				f = true;
			}
		}
		if(f)		cout << endl;
	}

	return 0;
}
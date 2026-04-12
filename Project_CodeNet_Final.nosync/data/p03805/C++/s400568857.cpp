#pragma region template
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 1e9 + 7, MAX = 1e18, larg = 1e5, INF = -1e9;
long long A, B, C, D, E, F, G, H, I, J, K, L, N, M, O, P, Q, R, S, T, U, V, W, x, y, z;
long long max_value = INF, max_index = -1;
long long min_value = MAX, min_index = -1;
typedef long long ll;
typedef pair<ll, ll> Pa;

bool draw[9][9] = { false };

int main() {
	cin >> N >> M;
	rep(i, M) {
		cin >> A >> B;
		draw[A][B] = true;
		draw[B][A] = true;
	}
	vector<int> vec;
	rep(i, N - 1) {
		vec.push_back(i + 2);
	}
	int cnt = 0;
	do{
		bool flag = true;
		flag &= draw[1][vec[0]];
		rep(i, N - 2) {
			flag &= draw[vec[i]][vec[i + 1]];
		}
		if (flag) cnt++;
	} while (std::next_permutation(vec.begin(), vec.end()));
	cout << cnt;
}
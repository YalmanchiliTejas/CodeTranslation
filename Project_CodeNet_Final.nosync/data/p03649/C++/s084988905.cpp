#pragma region template
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 1e9 + 7, MAX = LLONG_MAX, larg = 1e5, INF = -1e9;
long long A, B, C, D, E, F, G, H, I, J, K, L, N, M, O, P, Q, R, S, T, U, V, W;
typedef long long ll;
typedef pair<ll, ll> Pa;

ll arr[50];
ll maxv = 0, max_index = -1;

bool array_check() {
	bool flag = true;
	maxv = 0;
	rep(i, N) {
		flag &= (arr[i] < N);
		if (maxv < arr[i]) {
			maxv = arr[i];
			max_index = i;
		}
	}
	return flag;
}

int main() {
	cin >> N;
	ll sum = 0;
	rep(i, N) {
		cin >> arr[i];
        sum += arr[i]/N;
	}
    ll cnt = 0;
	while (!array_check()) {
        rep(i, N){
            ll tmp = arr[i];
            arr[i] -= (tmp/N)*N;
            arr[i] += (sum - tmp/N);
            cnt += tmp/N;
        }
        sum = 0;
        rep(i, N){
            sum += arr[i]/N;
        }
	}
    cout << cnt;
}

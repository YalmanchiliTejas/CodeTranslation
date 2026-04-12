#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main(void){
	ll N, X, M;
	cin >> N >> X >> M;
	vector<ll> A(1, X);
	vector<int> seen_idx(M, -1);
	seen_idx[X] = 0;
	ll lst = X;
	int cycle_idx;
	for (;;){
		lst = lst * lst % M;
		if (seen_idx[lst] >= 0){
			cycle_idx = seen_idx[lst];
			break;
		}
		seen_idx[lst] = A.size();
		A.push_back(lst);
	}

	ll res = 0;

	if (N <= cycle_idx){
		for (int i = 0; i < N; ++i)
			res += A[i];
		cout << res << endl;
		return 0;
	}

	ll cycle_sum = 0;
	int cycle_size = A.size() - cycle_idx;
	for (int i = cycle_idx; i < A.size(); ++i)
		cycle_sum += A[i];
	for (int i = 0; i < cycle_idx; ++i)
		res += A[i];
	N -= cycle_idx;
	res += cycle_sum * (N / cycle_size);
	N %= cycle_size;
	for (int i = 0; i < N; ++i)
		res += A[cycle_idx + i];

	cout << res << endl;


	return 0;
}
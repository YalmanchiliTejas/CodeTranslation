#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> P;
int amida[100000];
int main() {
	int N, Q;
	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		amida[i] = i;
	}
	vector<P> v;
	for (int i = 0; i < Q; i++) {
		int A, B;
		cin >> A >> B;
		A--; B--;
		v.push_back(P(A, B));
	}
	int zero = 0;
	set<int> ans;
	for (int i = 0; i < Q; i++) {
		if (zero > 0) ans.insert(amida[zero - 1]);
		if (zero < N - 1) ans.insert(amida[zero + 1]);
		if (amida[v[i].first] == 0) zero = v[i].second;
		else if (amida[v[i].second] == 0) zero = v[i].first;
		swap(amida[v[i].first], amida[v[i].second]);
	}
	if (zero > 0) ans.insert(amida[zero - 1]);
	if (zero < N - 1) ans.insert(amida[zero + 1]);
	cout << ans.size()+1 << endl;
}
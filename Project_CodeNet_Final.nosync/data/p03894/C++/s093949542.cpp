#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N, Q, NOW = 0;
	cin >> N >> Q;
	vector<long long> V(N), ANS;
	for (int i = 0; i < N; i++) V[i] = i;
	ANS.push_back(0);
	ANS.push_back(1);
	for (int i = 0; i < Q; i++) {
		long long A, B;
		cin >> A >> B;
		A--, B--;
		if (A == NOW || B == NOW) NOW = A + B - NOW;
		swap(V[A], V[B]);
		if (NOW != 0) ANS.push_back(V[NOW - 1]);
		if (NOW != N - 1) ANS.push_back(V[NOW + 1]);
	}
	sort(ANS.begin(), ANS.end());
	ANS.erase(unique(ANS.begin(), ANS.end()), ANS.end());
	cout << ANS.size() << endl;
}
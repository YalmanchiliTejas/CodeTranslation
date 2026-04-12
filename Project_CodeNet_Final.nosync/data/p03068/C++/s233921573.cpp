#include <bits/stdc++.h>
using namespace std;

template <class T> T* serchL(T* begin, T* end, T num) {
	T *p = begin;
	for (; p < end;p++) {
		if (&p >= num) {
			return p;
		}
	}

	return NULL;
}

int main() {
	ios::sync_with_stdio(false);
	string S;
	int N, K;
	cin >> N >> S >> K;
	
	char c = S.at(K-1);
	for (auto&i:S) {
		if (i != c) {
			i = '*';
		}
	}

	cout << S<<"\n";

	return 0;
}

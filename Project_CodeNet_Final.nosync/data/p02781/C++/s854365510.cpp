#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
const ll mod = 1000000007;
const ll mod998 = 998244353;
const ll intmax = 2147483647;
const ll llmax = 9223372036854775807;
const char sp = ' ';

string S, T;
int K, M;
ll res;

bool comp() {
	for (int i = 0; i < M; i++) {
		if (S[i] > T[i])return true;
		if (S[i] < T[i])return false;
	}
	return true;
}

int main() {
	cin >> S >> K;
	M = S.size();
	for (int i = 0; i < M; i++) {
		T.push_back('0');
	}
	if (K == 1) {
		for (int i = 0; i < M; i++) {
			for (char ci= '1'; ci <= '9'; ci++) {
				T[i] = ci;
				res += comp();
				T[i] = '0';
			}
		}
	}
	else if (K == 2) {
		for (int i = 0; i < M; i++) {
			for (char ci = '1'; ci <= '9'; ci++) {
				T[i] = ci;
				for (int j = i + 1; j < M; j++) {
					for (char cj = '1'; cj <= '9'; cj++) {
						T[j] = cj;
						res += comp();
						T[j] = '0';
					}
				}
				T[i] = '0';
			}
		}
	}
	else if (K == 3) {
		for (int i = 0; i < M; i++) {
			for (char ci = '1'; ci <= '9'; ci++) {
				T[i] = ci;
				for (int j = i + 1; j < M; j++) {
					for (char cj = '1'; cj <= '9'; cj++) {
						T[j] = cj;
						for (int k = j + 1; k < M; k++) {
							for (char ck = '1'; ck <= '9'; ck++) {
								T[k] = ck;
								res += comp();
								T[k] = '0';
							}
						}
						T[j] = '0';
					}
				}
				T[i] = '0';
			}
		}
	}
	cout << res << endl;
}
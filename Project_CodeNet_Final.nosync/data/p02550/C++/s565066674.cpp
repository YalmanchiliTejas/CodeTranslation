#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<tuple>
#include<time.h>

#define DIV 1000000007
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	ll N, X, M; cin >> N >> X >> M;

	vector<ll> A(M + 1);
	vector<int> used(M);
	A[1] = X, used[X] = 1;
	ll ans = 0;

	if (N <= M) {
		for (ll i = 2; i <= N; i++) {
			A[i] = A[i - 1] * A[i - 1] % M;
			ans += A[i];
		}
		ans += A[1];
		cout << ans << endl;
	}
	else {
		for (ll i = 2; i <= M; i++) {
			
			A[i] = A[i - 1] * A[i - 1] % M;
			A[i] %= M;
			//printf("A[%lld]=%lld \n", i, A[i]);
			if (used[A[i]]) {
				for (ll j = 1; j <= i; j++) {
					ans += A[j];
				}

				if (A[i] == 0)break;
				else if (A[i] == 1) {
					ans += N - i;
					break;
				}

				else {
					ll st = used[A[i]];
					ll temp = 0;
					for (int k = st; k < i; k++) {
						temp += A[k];
					}
					ans -= A[i];
					ans += temp * ((N - i + 1) / (i - st));
					for (int k = 0; k < (N - i + 1) % (i - st); k++) {
						ans += A[st + k];
					}
				
					//cout << "st=" << st << " i=" << i << " amari=" << (N - i + 1) % (i - st) << endl;
					break;
				}
			}

			else used[A[i]] = i;

		}

		cout << ans << endl;
	}
}
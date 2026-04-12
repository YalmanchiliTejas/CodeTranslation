#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

set<long long int> S;

long long int A[100005];
int N;

long long int INF = 999999999999;

map<long long int, int> C;

int main(void) {

	cin >> N;

		for (int i = 1; i <= N; i++) {
			cin >> A[i];
			
		}

		S.insert(-INF);
		S.insert(INF);

		int ans = 0;

		for (int i = 1; i <= N; i++) {
			auto y = S.upper_bound(A[i] - 1);
			y--;
			if ((*y) == -INF) { ans++; S.insert(A[i]); C[A[i]]++; }
			else {
				C[*y]--;
				if (C[*y] == 0) { S.erase(*y); }

				S.insert(A[i]); C[A[i]]++;
			}
		}

		cout << ans << endl;

	return 0;
}
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <map>
using namespace std;
#define REP(n) for(int i=0;i<n;i++)
long long al[51] = { 0 };
long long pans[51] = { 0 };

int type_cnt[100001] = { 0 };
long long func(long long N, long long X) {
	if (N == 0) {
		if (X >= 1) {
			return 1;
		}
		else {
			return 0;
		}
	}

	if (X <= 1 + al[N - 1]) {
		return func(N - 1, X - 1);
	}
	else if (X <= 2 + al[N - 1]) {
		return pans[N-1]+1;
	}
	else{
		return pans[N - 1] + 1 + func(N-1,X-al[N-1]-2);
	}
}



int main() {
	long long N,X;
	long long ans = 0;
	cin >> N >> X;
	al[0] = 1;
	pans[0] = 1;
	for (int i = 1; i < N;i++) {
		al[i] = al[i - 1] * 2 + 3;
		pans[i] = 2 * pans[i - 1] + 1;
	}


	ans = func(N, X);

	cout << ans << endl;
	return 0;
}
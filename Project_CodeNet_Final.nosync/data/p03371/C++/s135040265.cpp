#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPL(i,f,n) for(int i=f, i##_len=(n); i<i##_len; ++i)
typedef long long ll;

int main() {
	string MARCH = "MARCH";
	cin.tie(0);
	ios::sync_with_stdio(false);

	int A,B,C,X,Y;
	cin >> A >> B >> C >> X >> Y;
	int ans = C * 100000 * 2;
	REP(k, 100001) {
		ans = min(ans, 2*C*k + max(X-k,0) * A + +max(Y - k,0) * B);
	}
	cout << ans << endl;
	return 0;
}

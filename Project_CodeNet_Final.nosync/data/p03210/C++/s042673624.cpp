#include <bits/stdc++.h>
typedef long long int LL;
using namespace std;
#define INF (1LL << 60)
#define ALL(x) (x).begin(),(x).end()
#define FOR(i,k,n) for(int i=(k);(i)<(n);(i)++)
#define REP(i,n) for(int i = 0;(i)<(n);(i)++)
#define REPR(i,n) for(int i = n; i >= 0; i--)
#define F first
#define S second

int main() {
	int x;
	cin >> x;
	string ans;
	if (x == 7 || x == 5 || x == 3) {
		ans = "YES";
	}
	else {
		ans = "NO";
	}
	cout << ans << endl;

	return 0;
}

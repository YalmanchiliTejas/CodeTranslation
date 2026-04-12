#include <bits/stdc++.h>

#define FOR(i, a, b) for(long long int i=(a);i<=(b);i++)
#define RFOR(i, a, b) for(long long int i=(a);i>=(b);i--)
#define MOD 1000000007
#define INF 1000000000 //2000000000
#define LLINF 1000000000000000000 //9000000000000000000
#define PI 3.14159265358979

using namespace std;
typedef long long int ll;
typedef pair< long long int, long long  int> P;


int main(void) {
	int result[100] = {};
	int pos = 0;
	while (1) {
		int n;
		int s[101] = {};
		int mini = 1001;
		int maxi = -1;
		int total = 0;

		cin >> n;
		if (n == 0) {
			break;
		}
		pos++;
		FOR(i, 1, n) {
			cin >> s[i];
			if (maxi < s[i]) {
				maxi = s[i];
			}
			if (mini > s[i]) {
				mini = s[i];
			}
			total += s[i];
		}
		result[pos] = (total - maxi - mini) / (n - 2);
	}
	FOR(i, 1, pos) {
		cout << result[i] << endl;
	}

}

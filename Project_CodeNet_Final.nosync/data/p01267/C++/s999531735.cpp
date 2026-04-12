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
	
	while (1) {
		int n, a, b, c, x;
		int pos = 1;
		int time = -1;
		int y[101] = {};

		cin >> n >> a >> b >> c >> x;
		if (n == 0) {
			break;
		}
		FOR(i, 1, n) {
			cin >> y[i];
		}
			if (x == y[pos]) {
				pos++;
			}
		if (pos == n + 1) {
			time = 0;
		}
		FOR(i, 1, 10000) {
			if (time == 0) {
				break;
			}
			x = (a*x + b) % c;
			if (x == y[pos]) {
				pos++;
				if (pos == n + 1) {
					time = i;
					break;
				}
			}
			if (time != -1) {
				break;
			}
		}
		cout << time << endl;
	}
	
}

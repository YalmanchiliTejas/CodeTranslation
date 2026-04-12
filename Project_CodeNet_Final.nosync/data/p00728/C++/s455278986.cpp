#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
typedef unsigned int ui;
int main() {
	int n,s,sum,mi,ma;
	int i;
	while (cin >> n) {
		sum = 0;
		ma = 0; mi = (int)MOD;
		if (n == 0)break;
		for (i = 0; i < n; i++) {
			cin >> s; sum += s; mi = min(mi, s); ma = max(ma, s);
		}
		sum -= ma + mi;
		cout << sum / (n-2) << endl;
	}
	return 0;
}

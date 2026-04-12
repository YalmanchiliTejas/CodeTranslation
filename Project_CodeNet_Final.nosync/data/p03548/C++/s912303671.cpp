#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using IP = pair<int, int>;

const ll INF = 1LL << 62;
#define atcoder(int)1e9+7
#define Endl endl
#define mp make_pair
#define all(v) v.begin(),v.end()
#define pb push_back

ll gcd(ll a, ll b) {//最大公約数
	if (a%b == 0)return b;
	else gcd(b, a%b);
}

ll lcm(ll a, ll b) {//最小公倍数
	return (a / gcd(a, b))*b;
}

int main(){

	int x, y, z;
	cin >> x >> y >> z;
	int cnt = 0;

	x -= z;
	while (1) {
		if (x - (y + z) >= 0) {
			x -= y + z;
			cnt++;
		}
		else
			break;
	}

	cout << cnt << endl;
	return 0;
}
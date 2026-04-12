#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<utility>
#include<functional>
#include<stack>
#include<queue>
#include<cmath>

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
# define MOD 1000000000+7
# define INF 1000000000
typedef long long ll;
using namespace std;
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }


int main() {
	int n = 0;
	int h[100] = {};
	int ans = 0,maxi = 0;
	cin >> n;
	rep(i, n) {
		cin >> h[i];
	}
	rep(i, n) {

		if (h[i] >= maxi) {
			ans++;
			maxi = max(maxi, h[i]);
		}


	}

	cout << ans << endl;
}


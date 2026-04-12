#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
ll n;
ll x;
ll s[100];
ll pw[100];
ll ans = 0;
ll pty(ll a, ll b) {
	if (b == 0)return 0;
	if (a == 0)return 1;
	if (b == 1)return 0;
	if (1 + s[a - 1] >= b)return pty(a - 1, b - 1);
	return pw[a - 1] + 1 + pty(a - 1, min(s[a - 1], b - 2 - s[a - 1]));
}

int main() {
	cin >> n >> x;
	s[0] = 1;
	pw[0] = 1;
	for (int i = 1;i <= 50;i++) {
		s[i] = s[i - 1] * 2 + 3;
		pw[i] = pw[i - 1] * 2 + 1;
	}
	cout << pty(n, x) << endl;
	return 0;
}
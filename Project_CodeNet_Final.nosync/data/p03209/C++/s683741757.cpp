#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

//int re[51][1000000];

ll sol(ll n, ll x) {
	if(x == 0) return 0;
	if(n == 0) return 1;
	//if(x < 1000000 && re[n][x]) return re[n][x];
	ll len = (1LL << (n + 2)) - 3;
	ll llen = (len-3) / 2, res;
	x--;
	if(x <= llen) {
		res = sol(n-1, x);
	} else {
		res = 1LL + sol(n-1, x - llen - 1) + (1LL << n) - 1;
	}
	//if(x < 1000000)
	//	re[n][x] = res;
	return res;
}

int main()
{
	IO_OP;
	
	ll n, x;
	cin >> n >> x;
	cout << sol(n, x) << endl;
	
}


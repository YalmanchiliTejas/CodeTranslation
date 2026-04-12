#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>

#define range(i, n) for (i = 0; i < n; i++) 
#define rrange(i, n) for(i = n-1; i>=0; i--)

typedef long long int ll;

using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

vector<ll> p;
vector<ll> t;

ll ans(ll N, ll X);

ll ans(ll N, ll X) {
	if (N == 0) {
		if (X <= 0) return 0;
		else return 1;
	}
	else if (X <= 1 + t[N - 1]) {
		return ans(N - 1, X - 1);
	}
	else {
		return p[N - 1] + 1 + ans(N - 1, X - 2 - t[N - 1]);
	}
	
}

int main() {
	ll N, X;
	ll P, B;

	cin >> N >> X;



	int i;
	p.push_back(1);
	t.push_back(1);
	range(i, N) {
		p.push_back(p[i]*2 + 1);
		t.push_back(t[i]*2 + 3);
	}

	cout << dec << ans(N, X);

	return 0;
}

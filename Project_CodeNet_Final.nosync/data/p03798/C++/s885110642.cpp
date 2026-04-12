#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#include <functional>
using namespace std;

#define rep(i,x) for(ll i=0;i<x;i++)
#define repn(i,x) for(ll i=1;i<=x;i++)

typedef long long ll;
const ll INF = 1e17;
const ll MOD = 1000000007;
const ll MAX = 1000001;

ll max(ll a, ll b) {
	if (a > b) { return a; }
	return b;
}

ll min(ll a, ll b) {
	if (a > b) { return b; }
	return a;
}

ll gcd(ll a, ll b) {
	if (b == 0) { return a; }
	if (a < b) { return gcd(b, a); }
	return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) *b;
}

struct edge {
	ll ind;
	ll to;
	ll d;
};


///////////////////////////





int main() {

	ll N;
	cin >> N;
	string S;
	cin >> S;

	vector<bool> s(N + 1);
	repn(i, N) { 
		if (S[i - 1] == 'o') { s[i] = 1; }
		else { s[i] = 0; }
	}

	vector<ll> ans(N + 1, -1);
	
	rep(j, 4) {
		
		vector<bool> v(N + 1);
		v[1] = j % 2;
		v[2] = j / 2;


		for (ll i = 3; i <= N; i++) {
			v[i] = v[i - 2] ^ v[i - 1] ^ s[i - 1];
		}

		//repn(i, N)cout << v[i];
		//cout << endl;

		if (v[N - 1] ^ v[N] ^ v[1] == s[N] && v[N] ^ v[1] ^ v[2] == s[1]) {
			repn(i, N) { ans[i] = v[i];}
			break;
		}

		
	}

	//repn(i, N) cout << ans[i];

	if (ans[1] == -1) { cout << -1; }
	else {
		repn(i, N) {
			if (ans[i] == 0) { cout << "W"; }
			else { cout << "S"; }
		}
	}



	system("PAUSE");
}

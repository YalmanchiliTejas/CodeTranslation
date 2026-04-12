#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
typedef long long ll;

ll L[52] = {};
ll P[52] = {};
void make() {
	// layers
	L[0] = 1;
	FOR(i, 1, 51) {
		L[i] = 2*L[i-1] + 3; 
	}

	// p
	P[0] = 1;
	FOR(i, 1, 51) {
		P[i] = 2*P[i-1] + 1;
	}
}

ll layers_p_x(ll i, ll x) {
	if (i==0) {
		if (x==1) {
			return 1;
		} else {
			return 0;
		} 
	}
	if (x <= L[i-1] + 1) {
		return layers_p_x(i-1, x-1);
	}
	if (L[i] == x) {
		return P[i];
	}
	//return layers_p(i) - layers_p_x(i-1, layers(i) - x - 1);
	return 1 + P[i-1] + layers_p_x(i-1, x-2-L[i-1]);
}
int main(){
	ll n,x;
	cin >> n>>x;
	make();
	cout << layers_p_x(n,x) << endl;
	return 0;
}



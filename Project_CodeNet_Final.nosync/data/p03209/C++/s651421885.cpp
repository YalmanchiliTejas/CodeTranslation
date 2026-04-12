#include <iostream>

using namespace std;

#define rep(i,n) for(int i=0; i<(int)(n); i++)

typedef long long ll;

ll p(int l) {
	if(l == 0) return 1;
	else return 1 + 2 * p(l-1);
}

ll g(int l) {
	if(l == 0) return 1;
	else return 3 + 2 * g(l-1);
}

ll f(int l, ll n) {
	if(l == 0) return (n >= 1);
	else {
		ll u = g(l-1);
		if(n-1 <= u) return f(l-1, n-1);
		return p(l-1) + (n >= u+2) + f(l-1, n-u-2);
	}
}

int main(){
	int n;
	ll x;
	cin >> n >> x;
	cout << f(n, x) << endl;
	return 0;
}

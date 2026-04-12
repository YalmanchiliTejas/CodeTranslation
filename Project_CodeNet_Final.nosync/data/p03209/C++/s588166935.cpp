#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF (1<<20)

ll N, X;
vector<ll> a(55,0), p(55,0);

ll f(ll N, ll X) {
	if(N==0) return 1;
	if(X==1) return 0;
	if(1<X && X<=1+a[N-1]) return f(N-1,X-1);
	if(X==2+a[N-1]) return p[N-1]+1;
	if(2+a[N-1]<X && X<=2+2*a[N-1]) return p[N-1]+1+f(N-1,X-2-a[N-1]);
	if(X==3+2*a[N-1]) return 2*p[N-1]+1;
}

int main() {
	cin >> N >> X;

	a[0] = p[0] = 1;
	for (ll i = 1; i < N; i++) {
		a[i] = 2*a[i-1]+3;
		p[i] = 2*p[i-1]+1;
	}

	cout << f(N,X) << endl;
}


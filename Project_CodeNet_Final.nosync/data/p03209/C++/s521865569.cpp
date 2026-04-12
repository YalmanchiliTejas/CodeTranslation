#include <bits/stdc++.h>
using namespace std;

#define FOR(i, s, e)   for(int i = (s); i < (e); i++)
#define FOR64(i, s, e) for(ll  i = (s); i < (e); i++)
#define ALL(x)         (x).begin(), (x).end()
#define SORT(b, e)     sort((b), (e))
#define REV(b, e)      reverse((b), (e))
#define VSORT(v)       sort((v).begin(), (v).end())
#define VREV(v)        reverse((v).begin(), (v).end())
#define pb(a)          push_back(a)
#define INF            999999999

typedef long long ll;

vector<ll> a, p;

ll f(ll N, ll X)
{
	if(N == 0){
		if(X == 0)
			return 0;
		return 1;
	}

	if(X == 1){
		return 0;
	}
	else if(X <= 1 + a[N-1]){
		return f(N-1, X-1);
	}
	else if(X == 2 + a[N-1]){
		return p[N-1] + 1;
	}
	else if(X <= 2 + 2 * a[N-1]){
		return p[N-1] + 1 + f(N-1, X - 2 - a[N-1]);
	}
	else if(X == 3 + 2 * a[N-1]){
		return p[N-1] + 1 + p[N-1];
	}
}

int main()
{
	ll N, X;
	cin >> N >> X;
	a.resize(N + 1);
	p.resize(N + 1);
	a[0] = 1;
	p[0] = 1;
	FOR(i, 1, N+1){
		a[i] = 2 * a[i-1] + 3;
		p[i] = 2 * p[i-1] + 1;
	}

	cout <<  f(N, X) << endl;

	return 0;
}


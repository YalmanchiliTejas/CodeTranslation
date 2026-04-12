#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define ALL(A) A.begin(), A.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

ll a[51];	// バーガーの厚さ
ll p[51];	// パティの総数

ll f(int n, ll x){
	if (x == 1LL){
		return (n == 0 ? 1LL : 0LL);
	}else
	if (1LL < x && x <= a[n-1] + 1LL){
		return f(n - 1, x - 1LL);
	}else
	if (x == a[n-1] + 2LL){
		return p[n-1] + 1LL;
	}else
	if (a[n-1] + 2LL < x && x <= 2LL * a[n-1] + 2LL){
		return p[n-1] + 1LL + f(n - 1, x - a[n-1] - 2LL);
	}else
	if (x == 2LL * a[n-1] + 3LL){
		return 2LL * p[n-1] + 1LL;
	} // end if
}


int main()
{
	memset(a, 0LL, sizeof(a));
	memset(p, 0LL, sizeof(p));

	a[0] = 1LL;
	p[0] = 1LL;
	for (int i = 1; i <= 50; ++i){
		a[i] = 2LL * a[i-1] + 3LL;
		p[i] = 2LL * p[i-1] + 1LL;
	} // end for

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N; ll X; cin >> N >> X;
	
	ll res = f(N, X);
	cout << res << endl;

	return 0;
}
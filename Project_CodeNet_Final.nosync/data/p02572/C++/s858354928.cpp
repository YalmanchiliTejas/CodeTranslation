#include	<bits/stdc++.h>
using	namespace	std;
typedef	long long ll;

// int/long:		-2,147,483,648 - 2,147,483,647 (-2^31 <= int < 2^31)
// long/long long:	-9,223,372,036,854,775,808 - 9,223,372,036,854,775,807 (-2^63 <= long < 2^63)

#define	INF (1<<30)
//1,073,741,824
//= 536,870,912 *2

#define	MOD 1000000007
#define MAX 510000

#define	Rep0(i, n)	for (auto i=0; i<n; i++)
#define	Rep1(i, n)	for (auto i=1; i<=n; i++)
#define Sort(P)	sort(P.begin(), P.end())
#define Rev(P)	reverse(P.begin(), P.end())

ll	MPl(ll x, ll y) {
	return ((x+y)%MOD+MOD)%MOD;
}

ll	MMi(ll x, ll y) {
	return ((x-y)%MOD+MOD)%MOD;
}

ll	MMul(ll x, ll y) {
	return ((x*y)%MOD+MOD)%MOD;
}

// Array
vector<ll> fac(MAX, 0);
vector<ll> finv(MAX, 0);
vector<ll> inv(MAX, 0);

void	DivInit() { // fac, finv, inv
	fac.at(0) = 1;
	fac.at(1) = 1;
	finv.at(0) = 1;
	finv.at(1) = 1;
	inv.at(1) = 1;
	for (int i=2; i<MAX; i++) {
		fac.at(i) = (fac.at(i-1)*i) %MOD;
		inv.at(i) = MOD - (inv.at(MOD%i)*(MOD/i)) %MOD;
		finv.at(i) = (finv.at(i-1)*inv.at(i)) %MOD; 
	}
}

ll	MDiv(ll x, ll y) {
	if (1!=inv.at(1))
		DivInit();
	if (y<0) {
		x=-x;
		y=-y;
	}
	return ((x*inv.at(y))%MOD+MOD)%MOD;
}

ll	MComb(ll N, ll K) {
	if (1!=inv.at(1))
		DivInit();
	if (N<K)
		return 0;
	if ((N<0)||(K<0))
		return 0;
	return (fac.at(N) * ((finv.at(K)*finv.at(N-K)) %MOD)) %MOD;
}

int	main() {
	int N;
	cin >>N;
	vector<ll> A(N, 0);
	Rep0(i, N)
		cin >>A.at(i);
	ll ANS=0;
	ll ANS2=0;
	ll ANS3=0;
	for (auto AA: A) {
		ANS2 =MPl(ANS2, AA);
		ANS3 =MPl(ANS3, MMul(AA, AA));
	}
	ANS=MMul(ANS2, ANS2);
	ANS=MMi(ANS, ANS3);
	ANS=MDiv(ANS, 2);
	cout <<ANS <<endl;
	return 0;
}


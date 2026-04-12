#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <bitset>

using namespace std;
typedef pair<int, int> Pi;
typedef long long ll;
#define pii Pi
#define pll PL
#define Fi first
#define Se second
#define pb(x) push_back(x)
//#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;

const double PI = acos(-1);
const double EPS = 1e-9;

const int MX = 10005;
const int MM = 998244353;

ll F[MX], I[MX], IF[MX];

const int L = 1<<15, HL = L/2;

typedef vector<int> poly;

bool dir;

ll pw(ll a, ll b = MM-2){
	ll r = 1;
	while(b){
		if( b&1 ) r = r*a % MM;
		a = a*a % MM; b /= 2;
	}
	return r;
}

ll w[L+1];
ll primitive_root = pw(3, (MM-1)>>15); // 3 ** ((MM-1) / 2**19) % MM

void priproc()
{
	w[0] = 1;
	for(int i = 1; i <= L; i++) w[i] = primitive_root * w[i-1] % MM;
}

void DFT(poly &p, int n) {
	if (n == 1) return;
	int Hn = n>>1;
	poly p0(Hn), p1(Hn);
	for (int k = 0; k < Hn; k++) {
		p0[k] = p[k<<1];
		p1[k] = p[(k<<1)|1];
	}

	DFT(p0, Hn);
	DFT(p1, Hn);
	int dif = L/n;
	if( dir ){
		for (int i = 0, j = Hn, k = 0; k < HL; k += dif, i++, j++) {
			p[i] = (p0[i] + w[k] * p1[i]) % MM;
			p[j] = (p0[i] + MM - w[k] * p1[i]%MM) % MM;
		}
	}
	else{
		for (int i = 0, j = Hn, k = L; k > HL; k -= dif, i++, j++) {
			p[i] = (p0[i] + w[k] * p1[i]) % MM;
			p[j] = (p0[i] + MM - w[k] * p1[i]%MM) % MM;
		}
	}
}

void poly_multi(poly X, poly Y, poly &Z)
{
	dir = true; DFT(X, L); DFT(Y, L);
	for(int i = 0; i < L; i++)
		Z[i] = (ll)X[i] * Y[i] % MM;
	dir = false; DFT(Z, L);
	for(int i = 0; i < L; i++) Z[i] = Z[i] * pw(L) % MM;
	for(int i = L/2-5; i < L; i++) Z[i] = 0;
}

int main()
{
	priproc();
	I[1] = 1;
	for(int i = 2; i < MX; i++) I[i] = (MM - MM/i) * I[MM%i] % MM;
	F[0] = IF[0] = 1;
	for(int i = 1; i < MX; i++){
		F[i] = F[i-1] * i % MM;
		IF[i] = IF[i-1] * I[i] % MM;
	}

	string A, B;
	cin >> A >> B;

	int a = 0, b = 0;
	for(int i = 0; i < A.size(); i++){
		if( A[i] == '1' && B[i] == '1' ) a++;
		if( A[i] != B[i] ) b++;
	} b /= 2;
	poly X(L, 0), Y(L, 0);
	for(int i = 0; i <= 10000; i++) X[i] = IF[i+1] % MM;
	Y[0] = 1;
	int n = b;
	while(n){
		if( n&1 ) poly_multi(X, Y, Y);
		poly_multi(X, X, X); n /= 2;
	}

	ll ans = 0;
	for(int i = 0; i <= a; i++){
		ans = (ans + Y[i]) % MM;
	}
	ans = ans * F[a+b] % MM * F[a] % MM * F[b] % MM;
	printf("%lld\n", ans);
}

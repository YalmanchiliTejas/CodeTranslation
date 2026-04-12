#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 18;
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

const int MX = 1<<14 | 15;
const int MM = 998244353;

ll D[205][8005];
ll F[MX], FI[MX], I[MX];
int N, M;

ll C(ll a, ll b){
	if( a < b ) return 0;
	return F[a] * FI[b] % MM * FI[a-b] % MM;
}

#include <stdio.h>
#include <vector>
using namespace std;
 
#include <complex>
namespace FFT{
	// blog.myungwoo.kr/54
	typedef complex<double> base;
	typedef long long ll;

#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

	const double C_PI = acos(-1);

	void fft(vector <base> &a, bool invert){
		int n = sz(a);
		for(int i=0,j=0;i<n;++i) {
			if(i>j) swap(a[i],a[j]);
			for(int k=n>>1;(j^=k)<k;k>>=1);
		}
		for (int len=2;len<=n;len<<=1){
			double ang = 2*C_PI/len*(invert?-1:1);
			base wlen(cos(ang), sin(ang));
			for (int i=0;i<n;i+=len){
				base w(1);
				for (int j=0;j<len/2;j++){
					if((j & 511) == 511)w = base(cos(ang * j), sin(ang * j));	//오차가 클 경우 이 빈도를 늘린다. cos, sin 함수는 시간 부담이 있으니 주의
					base u = a[i+j], v = a[i+j+len/2]*w;
					a[i+j] = u+v;
					a[i+j+len/2] = u-v;
					w *= wlen;
				}
			}
		}
		if (invert){
			for (int i=0;i<n;i++) a[i] /= n;
		}
	}

	void multiply(const vector<int> &a,const vector<int> &b,vector<int> &res, const int MOD){
		vector <base> fa(all(a)), fb(all(b));
		int n = 1;
		while (n < max(sz(a),sz(b))) n <<= 1; n <<= 1;
		fa.resize(n); fb.resize(n);
		fft(fa,false); fft(fb,false);
		for (int i=0;i<n;i++) fa[i] *= fb[i];
		fft(fa,true);
		res.resize(n);
		for (int i=0;i<n;i++) res[i] = ((ll)(fa[i].real()+(fa[i].real()>0?0.5:-0.5))) % MOD;
	}

	void multiply_with_modulo(const vector<int> &a,const vector<int> &b,vector<int> &res, const int MOD){
		int n = 1;
		while (n < max(sz(a),sz(b))) n <<= 1; n <<= 1;
		vector <base> A(n), B(n);
		int L_BLOCK = 15;	//2^L_BLOCK ~= sqrt(MOD).
		for(int i=0;i<n;i++) A[i] = (i < sz(a) ? base(a[i] & ((1<<L_BLOCK)-1), a[i] >> L_BLOCK) : base(0));
		for(int i=0;i<n;i++) B[i] = (i < sz(b) ? base(b[i] & ((1<<L_BLOCK)-1), b[i] >> L_BLOCK) : base(0));
		fft(A, false); fft(B, false);
		vector <base> f1(n), f2(n), f3(n), f4(n);
		for(int i=0;i<n;i++) {
			int j=(n-i)&(n-1);
			f2[i]=(A[i]+conj(A[j]))*base(0.5,0);
			f1[i]=(A[i]-conj(A[j]))*base(0,-0.5);
			f4[i]=(B[i]+conj(B[j]))*base(0.5,0);
			f3[i]=(B[i]-conj(B[j]))*base(0,-0.5);
		}
		for(int i=0;i<n;i++) {
			A[i]=f1[i]*f3[i]+f1[i]*f4[i]*base(0,1);
			B[i]=f2[i]*f4[i]*base(0,1)+f2[i]*f3[i];
		}
		fft(A, true); fft(B, true);
		res.resize(n);
		for(int i=0;i<n;i++) {
			ll g1=(ll)(A[i].real()+0.5) % MOD;	//A[i].real > 0 이어야 함.
			ll g2=(ll)(A[i].imag()+0.5) % MOD;
			ll g3=(ll)(B[i].real()+0.5) % MOD;
			ll g4=(ll)(B[i].imag()+0.5) % MOD;
			res[i] = (g4 + ((g2+g3)<<L_BLOCK) + (g1<<(L_BLOCK<<1))) % MOD;
		}
	}

	void multiply_big(const vector<int> &a,const vector<int> &b, vector <ll> &res){
		// 단순히 오차가 심해 구하지 못하는 경우
		// 결과값은 long long 범위 안
		int n = 1;
		while (n < max(sz(a),sz(b))) n <<= 1; n <<= 1;
		vector <base> A(n), B(n);
		int L_BLOCK = 10;
		for(int i=0;i<n;i++) A[i] = (i < sz(a) ? base(a[i] & ((1<<L_BLOCK)-1), a[i] >> L_BLOCK) : base(0));
		for(int i=0;i<n;i++) B[i] = (i < sz(b) ? base(b[i] & ((1<<L_BLOCK)-1), b[i] >> L_BLOCK) : base(0));
		fft(A, false); fft(B, false);
		vector <base> f1(n), f2(n), f3(n), f4(n);
		for(int i=0;i<n;i++) {
			int j=(n-i)&(n-1);
			f2[i]=(A[i]+conj(A[j]))*base(0.5,0);
			f1[i]=(A[i]-conj(A[j]))*base(0,-0.5);
			f4[i]=(B[i]+conj(B[j]))*base(0.5,0);
			f3[i]=(B[i]-conj(B[j]))*base(0,-0.5);
		}
		for(int i=0;i<n;i++) {
			A[i]=f1[i]*f3[i]+f1[i]*f4[i]*base(0,1);
			B[i]=f2[i]*f4[i]*base(0,1)+f2[i]*f3[i];
		}
		fft(A, true); fft(B, true);
		res.resize(n);
		for(int i=0;i<n;i++) {
			ll g1=(ll)(A[i].real()+0.5);
			ll g2=(ll)(A[i].imag()+0.5);
			ll g3=(ll)(B[i].real()+0.5);
			ll g4=(ll)(B[i].imag()+0.5);
			res[i] = (g4 + ((g2+g3)<<(L_BLOCK)) + (g1<<(L_BLOCK<<1)));
		}
	}
}

void multi(ll Aa[MX], ll Ba[MX], ll Ca[MX], int N){
	vector<int> A(2*N), B(2*N), C(2*N);
	for(int i = 0; i <= N; i++) A[i] = Aa[i], B[i] = Ba[i];
	FFT::multiply_with_modulo(A, B, C, MM);
	for(int i = 0; i <= N*2; i++) Ca[i] = C[i];
}

int main()
{
	I[1] = F[0] = FI[0] = 1;
	for(int i = 2; i < MX; i++) I[i] = (MM - MM/i) * I[MM%i] % MM;
	for(int i = 1; i < MX; i++) F[i] = F[i-1] * i % MM;
	for(int i = 1; i < MX; i++) FI[i] = FI[i-1] * I[i] % MM;

	scanf("%d%d", &N, &M);
	for(int i = 0; i <= N; i++) D[0][i] = C(N, i);
	for(int i = 1; i <= M; i++){
		for(int j = 0; j <= N; j++) D[i][j] = D[i-1][j] * (MM-j) % MM;
		ll A[MX] = {}, B[MX] = {}, C[MX] = {};
		for(int j = 0; j <= N; j++) A[j] = D[i-1][j] * F[j+2] % MM;
		for(int j = 0; j <= N; j++) B[N-j] = FI[j+2];
		multi(A, B, C, N);
		for(int j = 0; j <= N; j++) D[i][j] = (D[i][j] + C[j+N] * FI[j]) % MM;
	}
	printf("%lld\n", D[M][0]);
}

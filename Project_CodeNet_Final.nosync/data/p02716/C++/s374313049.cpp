#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
//#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>

using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define Would
#define you
#define please

const int CM = 130000, CL = 12;
char cn[CM + CL], * ci = cn + CM + CL, * owa = cn + CM, ct;
const ll ma0 = 1157442765409226768;
const ll ma1 = 1085102592571150095;
const ll ma2 = 71777214294589695;
const ll ma3 = 281470681808895;
const ll ma4 = 4294967295;
inline int getint() {
	if (ci - owa > 0) {
		memcpy(cn, owa, CL);
		ci -= CM;
		fread(cn + CL, 1, CM, stdin);
	}
	int pn = 1;
	if (*ci == '-') {
		pn = -pn;
		ci++;
	}
	ll tmp = *(ll*)ci;
	int dig = ((tmp & ma0) ^ ma0) ? 68 - __builtin_ctzll((tmp & ma0) ^ ma0) : 0;
	tmp = tmp << dig & ma1;
	tmp = tmp * 10 + (tmp >> 8) & ma2;
	tmp = tmp * 100 + (tmp >> 16) & ma3;
	tmp = tmp * 10000 + (tmp >> 32) & ma4;
	ci += (64 - dig >> 3);
	while ((ct = *ci++) >= '0') tmp = tmp * 10 + ct - '0';
	return pn * tmp;
}

int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);


	int N;
	N = getint();

	ll dp00 = 0;
	ll dp11 = 0;
	ll dp02 = -1e18;

	int n = N / 2;
	if (N % 2) {
		rep(i, n) {
			int a = getint();
			if (dp11 < dp00) dp11 = dp00;
			dp00 += a;
			dp02 += a;
			if (dp02 < dp11) dp02 = dp11;
			dp11 += getint();
		}
		if (dp11 < dp00) dp11 = dp00;
		dp02 += getint();
		if (dp02 < dp11) dp02 = dp11;
		printf("%lld\n", dp02);
	}
	else {
		rep(i, n) {
			if (dp11 < dp00) dp11 = dp00;
			dp00 += getint();
			dp11 += getint();
		}
		if (dp11 < dp00) dp11 = dp00;
		printf("%lld\n", dp11);
	}


	Would you please return 0;
}
// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

// begin fast read template by CYJian (source: https://www.luogu.com.cn/paste/i11c3ppx)

namespace io {
	const int __SIZE = (1 << 21) + 1;
	char ibuf[__SIZE], *iS, *iT, obuf[__SIZE], *oS = obuf, *oT = oS + __SIZE - 1, __c, qu[55]; int __f, qr, _eof;
	#define Gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, __SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	inline void flush () { fwrite (obuf, 1, oS - obuf, stdout), oS = obuf; }
	inline void gc (char &x) { x = Gc(); }
	inline void pc (char x) { *oS ++ = x; if (oS == oT) flush (); }
	inline void pstr (const char *s) { int __len = strlen(s); for (__f = 0; __f < __len; ++__f) pc (s[__f]); }
	inline void gstr (char *s) { for(__c = Gc(); __c < 32 || __c > 126 || __c == ' ';)  __c = Gc();
		for(; __c > 31 && __c < 127 && __c != ' '; ++s, __c = Gc()) *s = __c; *s = 0; }
	template <class I> inline bool gi (I &x) { _eof = 0;
		for (__f = 1, __c = Gc(); (__c < '0' || __c > '9') && !_eof; __c = Gc()) { if (__c == '-') __f = -1; _eof |= __c == EOF; }
		for (x = 0; __c <= '9' && __c >= '0' && !_eof; __c = Gc()) x = x * 10 + (__c & 15), _eof |= __c == EOF; x *= __f; return !_eof; }
	template <class I> inline void print (I x) { if (!x) pc ('0'); if (x < 0) pc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10; while (qr) pc (qu[qr --]); }
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
} using io::pc; using io::gc; using io::pstr; using io::gstr; using io::gi; using io::print;

// end fast read template by CYJian

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
using ll=long long;
using pii=pair<int, int>;
//#define int ll
const int MOD = 1000000007;

// 0: AND
// 1: OR

int row[505], col[505];
uint64_t rowv[505], colv[505];
mt19937 rng;
bool det[505][505];
int n;

int buf[505][505];
uint64_t ans[505][505];

int make(int bit) {
	memset(det, 0, sizeof det);
	memset(buf, 0, sizeof buf);
	vector<pii> indep;
	rep(i, n) {
		if(row[i] == 0 && (bool)(rowv[i] & (1ull << bit))) {
			rep(j, n) {
				det[i][j] = 1;
				buf[i][j] = 1;
			}
		}
		if(row[i] == 1 && !(bool)(rowv[i] & (1ull << bit))) {
			rep(j, n) {
				det[i][j] = 1;
				buf[i][j] = 0;
			}
		}
	}
	rep(i, n) {
		if(col[i] == 0 && (bool)(colv[i] & (1ull << bit))) {
			rep(j, n) {
				if(det[j][i] && buf[j][i] == 0) return -1;
				det[j][i] = 1;
				buf[j][i] = 1;
			}
		}
		if(col[i] == 1 && !(bool)(colv[i] & (1ull << bit))) {
			rep(j, n) {
				if(det[j][i] && buf[j][i] == 1) return -1;
				det[j][i] = 1;
				buf[j][i] = 0;
			}
		}
	}
	rep(i, n) rep(j, n) if(!det[i][j]) indep.pb({i, j});
	int iter = 0;
	while(iter != 100000) {
		iter++;
		for(pii& k:indep)
			buf[k.fi][k.se] = rng() & 1;
		bool ok = 1;
		rep(i, n) {
			int tot = 1 - row[i];
			rep(j, n) tot = row[i] ? (tot | buf[i][j]) : (tot & buf[i][j]);
			if(tot != (bool)(rowv[i] & (1ull << bit))) {
				ok = 0; 
				break;
			}
		}
		if(!ok) continue;
		rep(i, n) {
			int tot = 1 - col[i];
			rep(j, n) tot = col[i] ? (tot | buf[j][i]) : (tot & buf[j][i]);
			if(tot != (bool)(colv[i] & (1ull << bit))) {
				ok = 0;
				break;
			}
		}
		if(!ok) continue;
		break;
	}
	if(iter == 100000) return -1;
	rep(i, n) rep(j, n) ans[i][j] |= ((uint64_t)(buf[i][j]) << bit);
	return 1;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    rng.seed(0x108616); // 108616 AK IOI
	gi(n);
	rep(i, n) gi(row[i]);
	rep(i, n) gi(col[i]);
	rep(i, n) gi(rowv[i]);
	rep(i, n) gi(colv[i]);
	rep(b, 64) {
		if(make(b) == -1) {
			print(-1);
			return 0;
		}
	}
	rep(i, n) {
		rep(j, n) {
			if(j) pc(' ');
			print(ans[i][j]);
		}
		pc('\n');
	}
}

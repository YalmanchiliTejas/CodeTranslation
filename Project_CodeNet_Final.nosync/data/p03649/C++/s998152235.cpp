#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using dbl = double;
using pii = pair<int, int>;
using pl4 = pair<ll, ll>;
using tl6 = tuple<ll, ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;
using vvs = vector<vs>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;
using vpl4 = vector<pl4>;
using vvpl4 = vector<vpl4>;
using vtl6 = vector<tl6>;
using vvtl6 = vector<vtl6>;
using vd = vector<dbl>;
using vvd = vector<vd>;

#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pob pop_back()
#define pf push_front
#define pof pop_front()
#define sz size()
#define bgn begin()
#define en end()
#define asn assign
#define emp empty()
#define fr front()
#define bk back()
#define clr clear()
#define ins insert
#define ers erase
#define res resize
#define tp top()

#define p_q priority_queue

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define rFOR(i,a,b) for(int i=(b);i>=(a);i--)
#define REP(i,a) FOR((i),0,(a)-1)
#define REP0(i,a) FOR((i),0,(a))
#define REP1(i,a) FOR((i),1,(a))
#define rREP(i,a) rFOR((i),0,(a)-1)
#define rREP0(i,a) rFOR((i),0,(a))
#define rREP1(i,a) rFOR((i),1,(a))
#define ROR(v,i) for(auto &(i):(v))
#define IOTA(a,n) iota((a).bgn,(a).en,(n))
#define SORT(a) sort((a).bgn,(a).en)
#define rSORT(a) sort((a).rbegin(),(a).rend())
#define UNIQUE(a) (a).erase(unique((a).bgn,(a).en),(a).en)
#define PREVP(a) prev_permutation((a).bgn,(a).en)
#define NEXTP(a) next_permutation((a).bgn,(a).en)
#define BINS(a,b) binary_search((a).bgn,(a).en,(b))
#define LOWB(a,b) (lower_bound((a).bgn,(a).en,(b))-(a).bgn)
#define UPB(a,b) (upper_bound((a).bgn,(a).en,(b))-(a).bgn)
#define CNT(a,b) count((a).bgn,(a).en,b)
#define SUM(a) accumulate((a).bgn,(a).en,0)
#define REV(a) reverse((a).bgn,(a).en)
#define REGS(a,b) regex_search((a),regex(b))
#define REGM(a,b) regex_match((a),regex(b))
#define yn(a) cout <<((a)?"yes":"no")<<endl;
#define Yn(a) cout <<((a)?"Yes":"No")<<endl;
#define YN(a) cout <<((a)?"YES":"NO")<<endl;
#define Imp(a) cout <<((a)?"Possible":"Impossible")<<endl;
#define IMP(a) cout <<((a)?"POSSIBLE":"IMPOSSIBLE")<<endl;
#define say(a) cout <<(a);
#define sal(a) cout <<(a)<<endl;
#define sak cout <<endl;
#define sas cout <<" ";
#define sat cout <<"\t";
#define dbg(a) cout <<(#a)<<": "<<(a)<<endl;
#define c2l(a) ((ll)(a-48))
#define a2l(a) ((ll)(a-97))
#define A2l(a) ((ll)(a-65))
#define l2c(a) ((char)(a+48))
#define l2a(a) ((char)(a+97))
#define l2A(a) ((char)(a+65))
#define DigN2(a) ((llabs(a)==0)?(1):((ll)(log2(double(llabs(a))))+1))
#define DigN10(a) ((llabs(a)==0)?(1):((ll)(log10(double(llabs(a))))+1))
#define Dig2(a,b) (((a)>>(b))&1)
#define Dig10(a,b) (ll)(((a)/((ll)(pow(10.0,(double)(b)))))%10)
#define Pow2(a) ((ll)(1)<<(a))
#define Pow10(a) ((ll)(pow(10.0,double(a))))
#define LSB(a) ((a)&(-(a)))
#define llin(a) ll (a);cin >>(a);
#define stin(a) string (a);cin >>(a);
#define vin(v) ROR((v),(i)){cin >>(i);};
#define vllin(v,N) vll (v)((N));vin(v);
#define vsin(v,N) vs (v)((N));vin(v);
#define rdn(a,b) ((a)/(b))
#define rou(a,b) ((((double(a)/double(b))-((a)/(b)))<0.5)?((a)/(b)):(((a)/(b))+1))
#define rup(a,b) ((((a)%(b))==0)?((a)/(b)):(((a)/(b))+1))
#define min(a,b) ((a<b)?(a):(b))
#define max(a,b) ((a>b)?(a):(b))
#define powll(a,b) (ll)(pow((double)(a),(double)(b)))
#define Triangle(x1,y1,x2,y2,x3,y3) (((x1)-(x2))*((y1)-(y3))-((x1)-(x3))*((y1)-(y2)))

#define svll SumV<ll>
#define svvll SumV2<ll>

#define int ll

const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;
//const ll MOD = 924844033;
//const ll MOD = 9007199254740881;
const ll INF = 1LL << 60;
const double PI = acos(-1.0);
const vll DX = { 0,-1,0,1,0,-1,1,1,-1 };
const vll DY = { 0,0,-1,0,1,-1,-1,1,1 };
const string alp = "abcdefghijklmnopqrstuvwxyz";
const string ALP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

ll Bset(ll a, ll b, ll c) {
	if (c) a |= b;
	else a &= ~b;
	return a;
}


template <typename valtype> class SumV {

public:
	ll size;
	vector<valtype> vec;
	vector<valtype> sumv;
	SumV(ll sizeget) {
		size = sizeget;
		Init();
	}
	SumV(vector<valtype> cpyvec) {
		size = cpyvec.sz;
		Init();
		vec = cpyvec;
		if (size > 0) Calc();
	}
	void Init() {
		vec.asn(size, 0);
		sumv.asn(size + 1, 0);
	}
	void Calc() {
		sumv[0] = 0;
		REP(i, size) {
			sumv[i + 1] = sumv[i] + vec[i];
		}
	}
	void Copy(vector<valtype> cpyvec) {
		size = cpyvec.sz;
		Init();
		vec = cpyvec;
		if (size > 0) Calc();
	}
	valtype sum(ll a, ll b) {
		if (a < 0 || a >= size || b < 0 || b >= size || a>b) return 0;
		return (sumv[b + 1] - sumv[a]);
	}
	void set(ll a, valtype x) {
		vec[a] = x;
//		Calc();
	}
	valtype operator[](const ll &i) const {
		return vec[i];
	}

};

template <typename valtype> class SumV2 {

public:
	vll size;
	vector<vector<valtype>> vec;
	vector<vector<valtype>> sumv;
	SumV2(ll sizeget0, ll sizeget1) {
		size.asn(2, 0);
		size[0] = sizeget0;
		size[1] = sizeget1;
		Init();
	}
	SumV2(vector<vector<valtype>> cpyvec) {
		size.asn(2, 0);
		size[0] = cpyvec.sz;
		size[1] = cpyvec[0].sz;
		Init();
		vec = cpyvec;
		Calc();
	}
	void Init() {
		vec.asn(size[0], vector<valtype>(size[1], 0));
		sumv.asn(size[0] + 1, vector<valtype>(size[1] + 1, 0));
	}
	void Calc() {
		sumv[0] = vector<valtype>(size[1] + 1, 0);
		REP(i, size[0]) {
			sumv[i][0] = 0;
			REP(j, size[1]) {
				sumv[i + 1][j + 1] = 0;
				sumv[i + 1][j + 1] = vec[i][j] - sum(i, i, j, j);
			}
		}
	}
	void Copy(vector<vector<valtype>> cpyvec) {
		size[0] = cpyvec.sz;
		size[1] = cpyvec[0].sz;
		Init();
		vec = cpyvec;
		Calc();
	}
	valtype sum(ll x1, ll x2, ll y1, ll y2) {
		if (x1 < 0 || x1 >= size[0] || x2 < 0 || x2 >= size[0] || y1 < 0 || y1 >= size[1] || y2 < 0 || y2 >= size[1] || x1>x2 || y1>y2) return 0;
		return (sumv[x2 + 1][y2 + 1] - sumv[x2 + 1][y1] - sumv[x1][y2 + 1] + sumv[x1][y1]);
	}
	void set(ll a, ll b, valtype x) {
		vec[a][b] = x;
//		Calc();
	}

};

class UFT {

public:
	ll size;
	ll mode;
	vll root;
	vll rank;
	UFT(ll sizeget, ll modeget = 0){
		size = sizeget;
		mode = modeget;
		root.res(size, 0);
		if (!mode) rank.res(size, 0);
		IOTA(root, 0);
	}
	ll find(ll x) {
		return root[x] == x ? x : root[x] = find(root[x]);
	}
	bool same(ll x, ll y) {
		return find(x) == find(y);
	}
	void unite(ll x, ll y) {
		x = find(x);
		y = find(y);
		if (x == y) return;
		if (mode) root[y] = x;
		else {
			if (rank[x] < rank[y]) {
				root[x] = y;
			}
			else {
				root[y] = x;
				if (rank[x] == rank[y]) rank[x]++;
			}
		}
	}
};

template <typename valtype> class SegT {

public:

	ll size;
	vector<valtype> v;

	valtype initv;
	function<valtype(valtype x, valtype y)> calc;

	SegT(ll sizeget, ll modeget = 0) {
		sizeset(sizeget);
		modeset(modeget);
		init();
	}
	SegT(vector<valtype> cpyvec, ll modeget = 0) {
		sizeset(cpyvec.sz);
		modeset(modeget);
		init();
		copy(cpyvec);
	}
	SegT(ll sizeget, valtype initvget, function<valtype(valtype x, valtype y)> calcget) {
		sizeset(sizeget);
		initv = initvget;
		calc = calcget;
		init();
	}
	SegT(vector<valtype> cpyvec, valtype initvget, function<valtype(valtype x, valtype y)> calcget) {
		sizeset(cpyvec.sz);
		initv = initvget;
		calc = calcget;
		init();
		copy(cpyvec);
	}
	void sizeset(ll rsize) {
		size = DigN2(rsize);
		if (rsize == Pow2(size - 1)) size--;
		return;
	}
	void modeset(ll mode) {
		switch (mode) {
		case 0:
			initv = 0;
			calc = [](valtype x, valtype y) {return x + y; };
			break;
		case 1:
			initv = INF;
			calc = [](valtype x, valtype y) {return min(x, y); };
			break;
		case 2:
			initv = -INF;
			calc = [](valtype x, valtype y) {return max(x, y); };
			break;
		}
		return;
	}
	void init() {
		v.asn(Pow2(size + 1) - 1, initv);
	}
	void copy(vector<valtype> cpyvec) {
		REP(i, min(cpyvec.sz, Pow2(size))) set(i, cpyvec[i]);
	}
	ll i2v(ll i) const{
		if (i < 0 || i >= Pow2(size)) return -1;
		return Pow2(size) + i - 1;
	}
	ll top(ll i) const{
		if (i == 0) return -1;
		return (i - 1) / 2;
	}
	pl4 bot(ll i) const{
		if (i + 1 >= Pow2(size)) return mp(-1, -1);
		return mp(2 * i + 1, 2 * i + 2);
	}
	void set(ll i, valtype x) {
		i = i2v(i);
		v[i] = x;
		while (i > 0) {
			i = top(i);
			v[i] = calc(v[bot(i).fi], v[bot(i).se]);
		}
		return;
	}
	void add(ll i, valtype x) {
		set(i, v[i2v(i)] + x);
		return;
	}
	valtype operator[](const ll &i) const {
		return v[i2v(i)];
	}
//	valtype que(ll a = 0, ll b = Pow2(size) - 1) {
	valtype que(ll a, ll b) {
		if (a == b) return v[i2v(a)];
		if (a > b) return initv;//swap(a, b);
		valtype ans = initv;
		ll ai = i2v(a);
		ll bi = i2v(b);
		FOR(i, 1, size + 1) {
			if (a > b) break;
			if (a%Pow2(i)) {
				ans = calc(ans, v[ai]);
				a += Pow2(i - 1);
				ai = top(ai) + 1;
			}
			else {
				ai = top(ai);
			}
			if (a > b) break;
			if ((b + 1) % Pow2(i)) {
				ans = calc(ans, v[bi]);
				b -= Pow2(i - 1);
				bi = top(bi) - 1;
			}
			else {
				bi = top(bi);
			}
			if (a > b) break;
		}
		return ans;
	}
	valtype que(ll b) {
		return que(0, b);
	}
	valtype que() {
		return que(0, Pow2(size) - 1);
	}


};

template <typename lentype> class Graph {

public:
	
	ll size;
	ll mode;
	ll mapmode;
	lentype zlen;
	lentype ilen;
	vector<map<ll, ll>> v2n;
	vvll n2v;
	vector<vector<lentype>> Edge;
	vector<pair<lentype, ll>> Primresult;

	Graph(ll sizeget = 0, ll mapmodeget = 0, ll modeget = 0, lentype zlenget = 0, lentype ilenget = INF) {
		size = sizeget;
		mapmode = mapmodeget;
		mode = modeget;
		zlen = zlenget;
		ilen = ilenget;
		init();
	}
	void init() {
		Edge.res(size);
		v2n.res(size);
		n2v.res(size);
		Primresult.asn(size, mp(ilen, -1));
	}
	lentype lenplus(lentype l, lentype r) {
		return l + r;
	}
	lentype lenequal(lentype l, lentype r) {
		return l == r;
	}
	lentype lenlcr(lentype l, lentype r) {
		return l < r;
	}
	ll addV(ll vs) {
		size += vs;
		init();
		return size;
	}
	void caddE(ll x, ll y, lentype c) {
		if (mapmode) v2n[x][y] = Edge[x].sz;
		Edge[x].pb(c);
		n2v[x].pb(y);
	}
	void csetE(ll x, ll y, lentype c) {
		if (mapmode) Edge[x][v2n[x][y]] = c;
	}
	void cersE(ll x, ll y) {
		if (mapmode) {
			ll n = v2n[x][y];
			Edge[x][n] = ilen;
			n2v[x][n] = -1;
			v2n[x].ers(y);
		}
	}
	void addE(ll x, ll y, lentype c) {
		caddE(x, y, c);
		if (!mode) caddE(y, x, c);
	}
	void setE(ll x, ll y, lentype c) {
		csetE(x, y, c);
		if (!mode) csetE(y, x, c);
	}
	void ersE(ll x, ll y, lentype c) {
		cersE(x, y, c);
		if (!mode) cersE(y, x, c);
	}
	lentype getE(ll x, ll y) {
		if (mapmode) {
			if (v2n[x].count(y)) {
				return Edge[x][v2n[x][y]];
			}
		}
		return ilen;
	}
	ll getVsz(ll x) {
		return Edge[x].sz;
	}
	pair<lentype, ll> getV(ll x, ll n) {
		if (n >= getVsz(x)) return mp(ilen, -1);
		return mp(Edge[x][n], n2v[x][n]);
	}

	vector<pair<lentype, vll>> Dijk(ll x) {
		vector<pair<lentype, vll>> result(size);
		REP(i, size) {
			result[i].fi = ilen;
			result[i].se = { -1 };
		}
		vll stat(size, 0);
		pair<lentype, ll> now;
		pair<lentype, ll> nowlv;
		SegT<pair<lentype, ll>> Q(size, mp(ilen, -1), [](pair<lentype, ll> l, pair<lentype, ll> r) {
			if (l.se == -1) return r;
			if (r.se == -1) return l;
			return l.fi < r.fi ? l : r;
		});
		Q.set(x, mp(zlen, x));
		result[x].fi = zlen;
		result[x].se = { -1 };
		while (Q.que(0, size - 1).se != -1) {
			now = Q.que(0, size - 1);
			Q.set(now.se, mp(ilen, -1));
			stat[now.se] = 1;
			REP(i, getVsz(now.se)) {
				nowlv = getV(now.se, i);
				if (stat[nowlv.se]) continue;
				if (Q[nowlv.se].se == -1) {
					result[nowlv.se].fi = lenplus(result[now.se].fi, nowlv.fi);
					result[nowlv.se].se = { now.se };
					Q.set(nowlv.se, mp(result[nowlv.se].fi, nowlv.se));
				}
				else {
					if (lenlcr(lenplus(result[now.se].fi, nowlv.fi), result[nowlv.se].fi)) {
						result[nowlv.se].fi = lenplus(result[now.se].fi, nowlv.fi);
						result[nowlv.se].se = { now.se };
						Q.set(nowlv.se, mp(result[nowlv.se].fi, nowlv.se));
					}
					else if (lenequal(lenplus(result[now.se].fi, nowlv.fi), result[nowlv.se].fi)) {
						result[nowlv.se].se.pb(now.se);
					}
				}
			}
		}
		return result;
	}

	lentype Prim(ll x = 0) {
		lentype ans = zlen;
		vll stat(size, 0);
		pair<lentype, ll> now;
		pair<lentype, ll> nowlv;
		SegT<pair<lentype, ll>> Q(size, mp(ilen, -1), [](pair<lentype, ll> l, pair<lentype, ll> r) {
			if (l.se == -1) return r;
			if (r.se == -1) return l;
			return l.fi < r.fi ? l : r;
		});
		Q.set(x, mp(zlen, x));
		Primresult[x] = mp(zlen, -1);
		while (Q.que(0, size - 1).se != -1) {
			now = Q.que(0, size - 1);
			Q.set(now.se, mp(ilen, -1));
			stat[now.se] = 1;
			ans = lenplus(ans, Primresult[now.se].fi);
			REP(i, getVsz(now.se)) {
				nowlv = getV(now.se, i);
				if (stat[nowlv.se]) continue;
				if (Q[nowlv.se].se == -1) {
					Primresult[nowlv.se] = mp(nowlv.fi, now.se);
					Q.set(nowlv.se, mp(Primresult[nowlv.se].fi, nowlv.se));
				}
				else {
					if (lenlcr(nowlv.fi, Primresult[nowlv.se].fi)) {
						Primresult[nowlv.se] = mp(nowlv.fi, now.se);
						Q.set(nowlv.se, mp(Primresult[nowlv.se].fi, nowlv.se));
					}
				}
			}
		}
		return ans;
	}

};


ll gcd(ll a, ll b) { if (b == 0)return a; return gcd(b, a%b); }
ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }

pl4 Bezout(ll a, ll b) {
	if (b != 0) {
		pl4 xy;
		xy = Bezout(b, a%b);
		return mp(xy.se, xy.fi - ((a / b)*xy.se));
	}
	if (b == 0) {
		return mp(1, 0);
	}
}
pl4 Bez(ll a, ll b, ll c) {
	pl4 xy;
	ll x, y, z, gc;
	xy = Bezout(a, b);
	gc = gcd(a, b);
	if (c%gc != 0) return mp(-1, -1);
	x = xy.fi*(c / gc); y = xy.se*(c / gc);
	if (x < 0) z = rup(-x, (b / gc));
	if (x >= 0) z = -x / (b / gc);
	x += z * (b / gc);
	y -= z * (a / gc);
	return mp(x, y);
}

void salv(vll v) {
	say("{");
	FOR(i, 0, v.sz - 1) {
		say(v[i]);
		if (i != v.sz - 1) say(",");
	}
	sal("}")
}

ll DigS10(ll n) {
	ll m = 0;
	FOR(i, 0, DigN10(n) - 1) {
		m += (ll)((llabs(n) % (ll)(pow(10.0, (double)(i + 1)))) / (ll)(pow(10.0, (double)i)));
	}
	return m;
}

ll isP(ll n) {
	if (n <= 1) return 0;
	FOR(i, 2, (ll)sqrt(n)) {
		if (n%i == 0) return 0;
	}
	return 1;
}

vll FactM(1, 1);
vll FactMI(1, 1);

ll PowM(ll a, ll b) {
	ll ans = 1, x = (a%MOD);
	FOR(i, 0, DigN2(b) - 1) {
		if (Dig2(b, i) == 1) ans = (ans*x) % MOD;
		if (i != (DigN2(b) - 1)) x = (x*x) % MOD;
	}
	return ans;
}

ll Mod(ll a) {
	a %= MOD;
	a = (a + MOD) % MOD;
	return a;
}

ll InvM(ll a) {
	a = Mod(a);
	a = PowM(a, MOD - 2);
	return a;
}

void CFactM(ll n) {
	if (FactM.sz <= n) {
		FOR(i, FactM.sz, n) {
			FactM.pb((FactM[i - 1] * (i%MOD)) % MOD);
		}
	}
	return;
}

void CFactMI(ll n) {
	CFactM(n);
	if (FactMI.sz < (n + 1)) FactMI.res(n + 1, -1);
	if (FactMI[n] == -1) FactMI[n] = PowM(FactM[n], MOD - 2);
	rFOR(i, 1, n - 1) {
		if (FactMI[i] != -1) break;
		FactMI[i] = ((FactMI[i + 1] * ((i + 1) % MOD)) % MOD);
	}
	return;
}

ll CombM(ll n, ll k) {
	if ((n < 0) || (k < 0)) return 0;
	if (n < k) return 0;
	if (n + 1 > FactMI.sz) CFactMI(n);
	return ((((FactMI[k] * FactMI[n - k]) % MOD)*FactM[n]) % MOD);
}

ll LIS(vll v, ll m = 0) {

	if (v.sz > 0) {
		ll ans = 0;
		vll dp(v.sz, INF);
		FOR(i, 0, v.sz - 1) {
			dp[m ? UPB(dp, v[i]) : LOWB(dp, v[i])] = v[i];
		}
		FOR(i, 0, v.sz - 1) {
			if (dp[i] == INF) break;
			ans++;
		}
		return ans;
	}
	else {
		return 0;
	}

}

void cmprs(vll& v) {
	if (v.sz == 0) return;
	vll vv(v);
	IOTA(vv, 0);
	sort(vv.bgn, vv.en, [&](ll v1, ll v2) {return v[v1] < v[v2]; });
	IOTA(v, 0);
	sort(v.bgn, v.en, [&](ll v1, ll v2) {return vv[v1] < vv[v2]; });
	return;
}

ll BblCnt(vll v) {
	cmprs(v);
	SegT<ll> b(v.sz, 0);
	ll ans = 0;
	REP(i, v.sz) {
		ans += (i - b.que(0, v[i]));
		b.add(v[i], 1);
	}
	return ans;
}

ll Bsrch(function<bool(ll x)> f, ll mi, ll ma) {
	ll ng = mi - 1, ok = ma, mid;
	while (ok - ng > 1) {
		mid = (ng + ok) / 2;
		(f(mid) ? ok : ng) = mid;
	}
	return ok;
}

/*
std::cout << std::fixed;
std::cout << std::setprecision(2) << 3.141; // "3.14"
std::cout << std::setprecision(2) << 3.0;   // "3.00"
*/



signed main() {

	llin(N);
	vllin(a, N);
	ll sum = 0, ans = 0;
	REP(i, N) {
		sum += a[i];
	}
	if (N*(N - 1) < sum) {
		ll k = 0;
		REP(i, N) {
			a[i] += (sum - N * (N - 1));
			if (a[i] / (N + 1) >= 1) {
				k += a[i] / (N + 1);
				a[i] %= (N + 1);
				a[i] += (N + 1);
				k--;
			}
		}
		REP(i, N) {
			a[i] += (k - (sum - N * (N - 1)));
		}
		ans += k;
	}
	while (1) {
		rSORT(a);
		if (a[0] >= N) {
			a[0] -= N;
			REP1(i, N - 1) {
				a[i]++;
			}
			ans++;
		}
		else break;
	}
	sal(ans);

}
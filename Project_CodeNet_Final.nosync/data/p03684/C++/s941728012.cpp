#include <bits/stdc++.h>
using namespace std;

template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
template <class T> using VVV = V<VV<T>>;
template <class S, class T> using P = pair<S, T>;
template <class S, class T, class U> using TP = tuple<S, T, U>;

using ll = long long;
using ull = unsigned long long;
using dbl = double;
using str = string;
using vll = V<ll>;
using vvll = V<vll>;
using vvvll = V<vvll>;
using pl = P<ll, ll>;
using tl = TP<ll, ll, ll>;
using vpl = V<pl>;
using vvpl = V<vpl>;
using vtl = V<tl>;
using vvtl = V<vtl>;
using vs = V<str>;
using vvs = V<vs>;
using vd = V<dbl>;
using vvd = V<vd>;
using qll = queue<ll>;
using qpl = queue<pl>;
using stll = stack<ll>;
using stpl = stack<pl>;
using mapll = map<ll, ll>;
using setll = set<ll>;
using pqll = priority_queue<ll>;

//#define int ll
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
#define inv inverse()

#define FOR(i,a,b) for(ll i=(a);i<=(ll)(b);i++)
#define rFOR(i,a,b) for(ll i=(b);i>=(ll)(a);i--)
#define REP(i,a) FOR((i),0,(ll)(a)-1)
#define REP0(i,a) FOR((i),0,(ll)(a))
#define REP1(i,a) FOR((i),1,(ll)(a))
#define rREP(i,a) rFOR((i),0,(ll)(a)-1)
#define rREP0(i,a) rFOR((i),0,(ll)(a))
#define rREP1(i,a) rFOR((i),1,(ll)(a))
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
#define yn(a) cout <<((a)?"yes":"no")<<"\n";
#define Yn(a) cout <<((a)?"Yes":"No")<<"\n";
#define YN(a) cout <<((a)?"YES":"NO")<<"\n";
#define imp(a) cout <<((a)?"possible":"impossible")<<"\n";
#define Imp(a) cout <<((a)?"Possible":"Impossible")<<"\n";
#define IMP(a) cout <<((a)?"POSSIBLE":"IMPOSSIBLE")<<"\n";
#define fs(a) cout <<((a)?"second":"first")<<"\n";
#define Fs(a) cout <<((a)?"Second":"First")<<"\n";
#define FS(a) cout <<((a)?"SECOND":"FIRST")<<"\n";
//#define say(a) cout <<(a);
//#define sal(a) cout <<(a)<<"\n";
#define sak cout <<"\n";
#define sas cout <<" ";
#define sat cout <<"\t";
#define dbg(a) cerr <<(#a)<<": "<<(a)<<"\n";
#define dbgs(...) dal(#__VA_ARGS__);dal(__VA_ARGS__);
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
/*#define llin(a) ll (a);cin >>(a);
#define llin2(a,b) ll (a),(b);cin >>(a)>>(b);
#define llin3(a,b,c) ll (a),(b),(c);cin >>(a)>>(b)>>(c);
#define stin(a) string (a);cin >>(a);*/
#define vin(v) ROR((v),(i)){cin >>(i);};
#define vllin(v,N) vll (v)((N));vin(v);
#define vllin2(a,b,N) vll (a)(N),(b)(N);REP(i,N){cin>>(a)[i]>>(b)[i];};
#define vsin(v,N) vs (v)((N));vin(v);
#define rdn(a,b) ((a)/(b))
#define rou(a,b) ((((double(a)/double(b))-((a)/(b)))<0.5)?((a)/(b)):(((a)/(b))+1))
#define rup(a,b) ((((a)%(b))==0)?((a)/(b)):(((a)/(b))+1))
#define powll(a,b) (ll)(pow((double)(a),(double)(b)))
#define Triangle(x1,y1,x2,y2,x3,y3) (((x1)-(x2))*((y1)-(y3))-((x1)-(x3))*((y1)-(y2)))

#define lam(lr) ([](auto l, auto r){lr})
#define elam(lr) ([=](auto l, auto r){lr})
#define clam(lr) ([&](auto l, auto r){lr})
#define min(...) Operation(MIN,__VA_ARGS__)
#define max(...) Operation(MAX,__VA_ARGS__)
#define gcd(...) Operation(GCD,__VA_ARGS__)
#define lcm(...) Operation(LCM,__VA_ARGS__)
#define vmin(...) VOperation(MIN,__VA_ARGS__)
#define vmax(...) VOperation(MAX,__VA_ARGS__)
#define vgcd(...) VOperation(GCD,__VA_ARGS__)
#define vlcm(...) VOperation(LCM,__VA_ARGS__)
#define vsum(...) VOperation(ADD,__VA_ARGS__)
#define vpro(...) VOperation(MUL,__VA_ARGS__)
#define emin(a, ...) ((a)=min((a),__VA_ARGS__))
#define emax(a, ...) ((a)=max((a),__VA_ARGS__))
#define egcd(a, ...) ((a)=gcd((a),__VA_ARGS__))
#define elcm(a, ...) ((a)=lcm((a),__VA_ARGS__))
#define ActPair(T) P<T, function<T(T, T)>>
#define BoolPair(T) P<T, function<bool(T, T)>>
#define ope Operation
#define vope VOperation

#define svll SumV<ll>
#define svvll SumV2<ll>

#define li(...) ll __VA_ARGS__;Input(__VA_ARGS__);
#define si(...) str __VA_ARGS__;Input(__VA_ARGS__);
//#define vli(size, ...) vll __VA_ARGS__;vInitInput(size,__VA_ARGS__);
#define vlr(size, ...) vll __VA_ARGS__;vInitInputR(size,__VA_ARGS__);
#define vlc(size, ...) vll __VA_ARGS__;vInitInputC(size,__VA_ARGS__);
#define vli(size, ...) vll __VA_ARGS__;vInitInputR(size,__VA_ARGS__);
#define vsr(size, ...) vs __VA_ARGS__;vInitInputR(size,__VA_ARGS__);
#define vsc(size, ...) vs __VA_ARGS__;vInitInputC(size,__VA_ARGS__);
#define vsi(size, ...) vs __VA_ARGS__;vInitInputR(size,__VA_ARGS__);
#define vli2(rowSize,columnSize, ...) vvll __VA_ARGS__;vInitInput2(rowSize,columnSize,__VA_ARGS__);
#define vplr(size, ...) vpl __VA_ARGS__;vInitInputR(size,__VA_ARGS__);
#define vplc(size, ...) vpl __VA_ARGS__;vInitInputC(size,__VA_ARGS__);
#define vpli(size, ...) vpl __VA_ARGS__;vInitInputR(size,__VA_ARGS__);

const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;
//const ll MOD = 924844033;
//const ll MOD = 9007199254740881;
const ll INF = 1LL << 60;//1.15e18
const double PI = acos(-1.0);
const vll DX = { 0,-1,0,1,0,-1,1,1,-1 };
const vll DY = { 0,0,-1,0,1,-1,-1,1,1 };
const str alp = "abcdefghijklmnopqrstuvwxyz";
const str ALP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

template <class S, class T> istream &operator>>(istream &in, P<S, T> &p) { return in >> p.fi >> p.se; }
template <class T> istream &operator>>(istream &in, V<T> &v) { REP(i, v.sz) in >> v[i]; return in; }

void Input() {}
template <class Var, class... Args> void Input(Var& var, Args&... args) {
	cin >> var;
	Input(args...);
}

void vInit(ll size) {}
template <class T, class... Args> void vInit(ll size, V<T>& v, Args&... args) {
	v.res(size);
	vInit(size, args...);
}
void vInput(ll size) {}
template <class T, class... Args> void vInput(ll size, V<T>& v, Args&... args) {
	REP(i, size) cin >> v[i];
	vInput(size, args...);
}
void vInputR(ll size) {}
template <class T, class... Args> void vInputR(ll size, V<T>& v, Args&... args) {
	REP(i, size) cin >> v[i];
	vInputR(size, args...);
}
void vInputNumC(ll num) {}
template <class T, class... Args> void vInputNumC(ll num, V<T>& v, Args&... args) {
	cin >> v[num];
	vInputNumC(num, args...);
}
void vInputC(ll size) {}
template <class... Args> void vInputC(ll size, Args&... args) {
	REP(i, size) vInputNumC(i, args...);
}
void vInitInputR(ll size) {}
template <class... Args> void vInitInputR(ll size, Args&... args) {
	vInit(size, args...);
	vInputR(size, args...);
}
void vInitInputC(ll size) {}
template <class... Args> void vInitInputC(ll size, Args&... args) {
	vInit(size, args...);
	vInputC(size, args...);
}
void vInit2(ll rowSize, ll columnSize) {}
template <class T, class... Args> void vInit2(ll rowSize, ll columnSize, V<V<T>>& v, Args&... args) {
	v.asn(rowSize, V<T>(columnSize));
	vInit2(rowSize, columnSize, args...);
}
void vInput2(ll rowSize, ll columnSize) {}
template <class T, class... Args> void vInput2(ll rowSize, ll columnSize, V<V<T>>& v, Args&... args) {
	REP(r, rowSize) {
		REP(c, columnSize) {
			cin >> v[r][c];
		}
	}
	vInput2(rowSize, columnSize, args...);
}
void vInitInput2(ll rowSize, ll columnSize) {}
template <class... Args> void vInitInput2(ll rowSize, ll columnSize, Args&... args) {
	vInit2(rowSize, columnSize, args...);
	vInput2(rowSize, columnSize, args...);
}

template <class S, class T> ostream &operator<<(ostream &out, const P<S, T> &p) {
	return out << "[" << p.fi << ", " << p.se << "]";
}

template <class T> ostream &operator<<(ostream &out, V<T> &v) {
	if (v.emp) return out << "{}";
	else {
		auto itr = v.bgn;
		out << "{" << *itr;
		itr++;
		while (itr != v.en) {
			out << ", " << *itr;
			itr++;
		}
		out << "}";
		return out;
	}
}

template <class S, class T> ostream &operator<<(ostream &out, const map<S, T> &m) {
	if (m.emp) return out << "<[]>";
	else {
		auto itr = m.bgn;
		out << "< [" << (itr->fi) << ": " << (itr->se);
		itr++;
		while (itr != m.en) {
			out << "], [" << (itr->fi) << ": " << (itr->se);
			itr++;
		}
		out << "] >";
		return out;
	}
}

template <class T> ostream &operator<<(ostream &out, const set<T> &s) {
	if (s.emp) return out << "<>";
	else {
		auto itr = s.bgn;
		out << "<" << *itr;
		itr++;
		while (itr != s.en) {
			out << ", " << *itr;
			itr++;
		}
		out << ">";
		return out;
	}
}

void say() {}
template <class T> void say(T t) { cout << t; }
template <class Head, class... Body> void say(Head head, Body... body) {
	cout << head << " ";
	say(body...);
}
void sal() { cout << "\n"; }
template <class... Args> void sal(Args... args) {
	say(args...);
	cout << "\n";
}

void day() {}
template <class T> void day(T t) { cerr << t; }
template <class Head, class... Body> void day(Head head, Body... body) {
	cerr << head << " ";
	day(body...);
}
void dal() { cerr << "\n"; }
template <class... Args> void dal(Args... args) {
	day(args...);
	cerr << "\n";
}

void salv() {}
template <class T> void salv(V<T> v) {
	if (v.emp) sal();
	else {
		auto itr = v.bgn;
		say(*itr);
		itr++;
		while (itr != v.en) {
			sas;
			say(*itr);
			itr++;
		}
		sak;
	}
}
template <class T> void salv(V<V<T>> v) {
	if (v.emp) sal();
	else {
		ROR(v, i) salv(i);
	}
}
template <class T, class... Args> void salv(T v, Args... args) {
	salv(v);
	salv(args...);
}


template <class L, class R> auto Gcd(L l, R r) -> decltype(l + r) {
	if (l < r) swap(l, r);
	return r ? Gcd(r, l%r) : l;
}
template <class L, class R> auto Lcm(L l, R r) {
	if (!l || !r) return 0;
	return l / Gcd(l, r) * r;
}

auto LES = mp(INF, lam(return l < r;));
auto GRT = mp(-INF, lam(return l > r;));
auto EQ = mp(0, lam(return l == r;));

auto ADD = mp(0, lam(return l + r;));
auto SUB = mp(0, lam(return l - r;));
auto MUL = mp(1, lam(return l * r;));
auto DIV = mp(1, lam(return l / r;));
auto MDL = mp(1, lam(return l % r;));
auto XOR = mp(0, lam(return l ^ r;));
auto OR = mp(0, lam(return l | r;));
auto AND = mp(((ll)(1) << 63) - 1, lam(return l & r;));
auto MIN = mp(INF, lam(return (l < r) ? l : r;));
auto MAX = mp(-INF, lam(return (l > r) ? l : r;));
auto GCD = mp(0, lam(return Gcd(l, r);));
auto LCM = mp(1, lam(return Lcm(l, r);));

/*
auto ADD = mp(0, [](auto l, auto r) { return l + r; });
auto SUB = mp(1, [](auto l, auto r) { return l - r; });
auto MUL = mp(1, [](auto l, auto r) { return l * r; });
auto DIV = mp(0, [](auto l, auto r) { return l / r; });
auto MDL = mp(0, [](auto l, auto r) { return l % r; });
auto XOR = mp(0, [](auto l, auto r) { return l ^ r; });
auto OR = mp(0, [](auto l, auto r) { return l | r; });
auto AND = mp(((ll)(1) << 63) - 1, [](auto l, auto r) { return l & r; });
auto MIN = mp(INF, [](auto l, auto r) { return (l < r) ? l : r; });
auto MAX = mp(-INF, [](auto l, auto r) { return (l > r) ? l : r; });
auto GCD = mp(0, [](auto l, auto r) { return gcd(l, r); });
auto LCM = mp(1, [](auto l, auto r) { return lcm(l, r); });
*/

template <class OperationType> auto Operation(OperationType A) { return A.fi; }
template <class OperationType, class T> auto Operation(OperationType A, T x) { return x; }
template <class OperationType, class T, class... Args> auto Operation(OperationType A, T x, Args... args) {
	auto tmp = Operation(A, args...);
	return A.se(x, tmp);
}

template <class OperationType> auto VOperation(OperationType A) { return A.fi; }
template <class OperationType, class T> auto VOperation(OperationType A, T x) { return x; }
template <class OperationType, class T> auto VOperation(OperationType A, V<T> x) {
	T tmp = A.fi;
	ROR(x, i) tmp = A.se(tmp, i);
	return tmp;
}
template <class OperationType, class T> auto VOperation(OperationType A, V<V<T>> x) {
	T tmp = A.fi;
	ROR(x, i) ROR(i, j) tmp = A.se(tmp, j);
	return tmp;
}
template <class OperationType, class T> auto VOperation(OperationType A, V<V<V<T>>> x) {
	T tmp = A.fi;
	ROR(x, i) ROR(i, j) ROR(j, k) tmp = A.se(tmp, k);
	return tmp;
}
template <class OperationType, class T> auto VOperation(OperationType A, V<V<V<V<T>>>> x) {
	T tmp = A.fi;
	ROR(x, i) ROR(i, j) ROR(j, k) ROR(k, l) tmp = A.se(tmp, l);
	return tmp;
}
template <class OperationType, class T, class... Args> auto VOperation(OperationType A, T x, Args... args) {
	auto xResult = VOperation(A, x);
	auto tmp = VOperation(A, args...);
	return A.se(xResult, tmp);
}


ll Bset(ll a, ll b, ll c) {
	if (c) a |= b;
	else a &= ~b;
	return a;
}


struct UFT {

public:
	ll tsize;
	ll mode;
	vll par;
	vll rank;
	UFT() {}
	UFT(const UFT &uft) {}
	UFT(ll tsizeget, ll modeget = 0){
		tsize = tsizeget;
		mode = modeget;
		par.asn(tsize, -1);
		if (!mode) rank.res(tsize, 0);
	}
	ll root(ll x) {
		return par[x] < 0 ? x : par[x] = root(par[x]);
	}
	bool isRoot(ll x) {
		return x == root(x);
	}
	bool same(ll x, ll y) {
		return root(x) == root(y);
	}
	void merge(ll x, ll y) {
		x = root(x);
		y = root(y);
		if (x == y) return;
		if (mode) {
			par[x] += par[y];
			par[y] = x;
		}
		else {
			if (rank[x] < rank[y]) {
				par[y] += par[x];
				par[x] = y;
			}
			else {
				par[x] += par[y];
				par[y] = x;
				if (rank[x] == rank[y]) rank[x]++;
			}
		}
	}
	ll size(ll x) {
		return -par[root(x)];
	}
};

struct pUFT {

public:

	ll tsize;
	ll now;
	vll par;
	vll rank;
	vll mtime;
	vvll sizepi;
	vvll sizepv;

	pUFT(){}
	pUFT(const pUFT &puft) {}

	pUFT(ll tsizeget) {
		tsize = tsizeget;
		now = 0;
		par.asn(tsize, -1);
		rank.asn(tsize, 0);
		mtime.asn(tsize, INF);
		sizepi.asn(tsize, { 0 });
		sizepv.asn(tsize, { 1 });
	}
	ll root(ll x, ll t) {
		return (mtime[x] > t) ? x : root(par[x], t);
	}
	bool same(ll x, ll y, ll t) {
		return root(x, t) == root(y, t);
	}
	ll merge(ll x, ll y) {
		now++;
		x = root(x, now);
		y = root(y, now);
		if (x != y) {
			if (rank[x] < rank[y]) {
				par[y] += par[x];
				sizepi[y].pb(now);
				sizepv[y].pb(-par[y]);
				par[x] = y;
				mtime[x] = now;
			}
			else {
				par[x] += par[y];
				sizepi[x].pb(now);
				sizepv[x].pb(-par[x]);
				par[y] = x;
				mtime[y] = now;
				if (rank[x] == rank[y]) rank[x]++;
			}
		}
		return now;
	}
	ll size(ll x, ll t) {
		x = root(x, t);
		return sizepv[x][UPB(sizepi[x], t) - 1];
	}

};

struct wUFT {
public:
	ll tsize;
	ll mode;
	vll par;
	vll rank;
	vll dweight;
	wUFT() {}
	wUFT(const wUFT &wuft) {}
	wUFT(ll tsizeget, ll modeget = 0) {
		tsize = tsizeget;
		mode = modeget;
		par.asn(tsize, -1);
		if (!mode) rank.res(tsize, 0);
		dweight.asn(tsize, 0);
	}
	ll root(ll x) {
		if (par[x] < 0) return x;
		else {
			ll r = root(par[x]);
			dweight[x] += dweight[par[x]];
			return par[x] = r;
		}
	}
	ll weight(ll x) {
		root(x);
		return dweight[x];
	}
	ll diff(ll x, ll y) {
		return weight(y) - weight(x);
	}
	bool isRoot(ll x) {
		return x == root(x);
	}
	bool same(ll x, ll y) {
		return root(x) == root(y);
	}
	void merge(ll x, ll y, ll w) {
		w += weight(x);
		w -= weight(y);
		x = root(x);
		y = root(y);
		if (x == y) return;
		if (mode) {
			par[x] += par[y];
			par[y] = x;
		}
		else {
			if (rank[x] < rank[y]) {
				par[y] += par[x];
				par[x] = y;
				dweight[x] = -w;
			}
			else {
				par[x] += par[y];
				par[y] = x;
				if (rank[x] == rank[y]) rank[x]++;
				dweight[y] = w;
			}
		}
	}
	ll size(ll x) {
		return -par[root(x)];
	}
};

template <typename valtype> class SegT {

public:

	ll size;
	vector<valtype> v;

	valtype initv;
	function<valtype(valtype x, valtype y)> calc;

	SegT() {}
	SegT(const SegT &segt) {}

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
	pl bot(ll i) const{
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

/*
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

	Graph() {}
	Graph(const Graph &graph) {}

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
*/

/*template <class Type> class DP {

public:

	vector<Type> v;
	Type initv;
	vll size, block;

	DP() {}
	DP(const DP &dp) {}

	template<class... Args> DP(Args... args) {
		block.asn(1, 1);
		Initialize(args...);
	}

	void Initialize(Type initv_) {
		initv = initv_;
		v.asn(block.bk, initv);
	}
	template<class... Args> void Initialize(ll val, Args... args) {
		size.pb(val);
		block.pb(block.bk*val);
		Initialize(args...);
	}



};*/


pl Bezout(ll a, ll b) {
	if (b != 0) {
		pl xy;
		xy = Bezout(b, a%b);
		return mp(xy.se, xy.fi - ((a / b)*xy.se));
	}
	else {
		return mp(1, 0);
	}
}
pl Bez(ll a, ll b, ll c) {
	pl xy;
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

ll DigS10(ll n) {
	ll ans = 0;
	while(1) {
		ans += n % 10;
		n /= 10;
		if (!n) break;
	}
	return ans;
}

ll isP(ll n) {
	if (n <= 1) return 0;
	FOR(i, 2, (ll)sqrt(n) + 1) {
		if (n%i == 0) return 0;
	}
	return 1;
}

ll Tot(ll n) {
	if (n <= 0) return 0;
	ll ans = n, x = 2;
	while (x*x <= n) {
		if (n%x == 0) {
			ans -= ans / x;
			while (n%x == 0) n /= x;
		}
		x++;
	}
	if (n > 1) ans -= ans / n;
	return ans;
}

template <class T> struct Graph {
public:
	ll vSize;
	ll eMode;
	ll mapMode;
	ActPair(T) Add;
	BoolPair(T) Lesser;
	BoolPair(T) Equal;
	V<V<P<T, ll>>> adj;
	map<pl, T> len;
	Graph(ll vSize, ll eMode = 0, ll mapMode = 0, ActPair(T) Add = ADD, BoolPair(T) Lesser = LES, BoolPair(T) Equal = EQ) : vSize(vSize), eMode(eMode), mapMode(mapMode), Add(Add), Lesser(Lesser), Equal(Equal) { Init(); }
	void Init() {
		adj.asn(vSize, V<P<T, ll>>());
	}
	void AddE(ll x, ll y, T cost) {
		iAddE(x, y, cost);
		if (!eMode) iAddE(y, x, cost);
	}
	void iAddE(ll x, ll y, T cost) {
		adj[x].pb(mp(cost, y));
		if (mapMode) len[mp(x, y)] = cost;
	}
	P<bool, T> getE(ll x, ll y) {
		if (!len.count(mp(x, y))) return mp(false, Lesser.fi);
		return mp(true, len[mp(x, y)]);
	}
	V<T> Dijk(ll x) {
		V<T> ans(vSize, Lesser.fi);
		if (x < 0 || x >= vSize) return ans;
		SegT<P<T, ll>> segt(vSize, mp(Lesser.fi, -1), clam(
			if (l.se < 0) return r;
		if (r.se < 0) return l;
		return Lesser.se(l.fi, r.fi) ? l : r;
		));
		segt.set(x, mp(Add.fi, x));
		P<T, ll> now;
		while ((now = segt.que(0, vSize - 1)).se >= 0) {
			ans[now.se] = segt[now.se].fi;
			segt.set(now.se, mp(Lesser.fi, -2));
			ROR(adj[now.se], i) {
				if (segt[i.se].se == -2) continue;
				if (segt[i.se].se == -1) {
					segt.set(i.se, mp(Add.se(ans[now.se], i.fi), i.se));
					continue;
				}
				if (Lesser.se(Add.se(ans[now.se], i.fi), segt[i.se].fi)) {
					segt.set(i.se, mp(Add.se(ans[now.se], i.fi), i.se));
					continue;
				}
			}
		}
		return ans;
	}
	V<P<T, vll>> rDijk(ll x) {
		V<P<T, vll>> ans(vSize, mp(Lesser.fi, vll()));
		if (x < 0 || x >= vSize) return ans;
		SegT<P<T, ll>> segt(vSize, mp(Lesser.fi, -1), clam(
			if (l.se < 0) return r;
		if (r.se < 0) return l;
		return Lesser.se(l.fi, r.fi) ? l : r;
		));
		segt.set(x, mp(Add.fi, x));
		P<T, ll> now;
		while ((now = segt.que(0, vSize - 1)).se >= 0) {
			ans[now.se].fi = segt[now.se].fi;
			segt.set(now.se, mp(Lesser.fi, -2));
			ROR(adj[now.se], i) {
				if (segt[i.se].se == -2) continue;
				if (segt[i.se].se == -1) {
					segt.set(i.se, mp(Add.se(ans[now.se].fi, i.fi), i.se));
					ans[i.se].se = { now.se };
					continue;
				}
				if (Lesser.se(Add.se(ans[now.se].fi, i.fi), segt[i.se].fi)) {
					segt.set(i.se, mp(Add.se(ans[now.se].fi, i.fi), i.se));
					ans[i.se].se = { now.se };
					continue;
				}
				if (Equal.se(Add.se(ans[now.se].fi, i.fi), segt[i.se].fi)) {
					ans[i.se].se.pb(now.se);
					continue;
				}
			}
		}
		return ans;
	}

	P<T,V<P<T, vll>>> rPrim(ll x) {
		P<T, V<P<T, vll>>> ans = mp(Add.fi, V<P<T, vll>>(vSize, mp(Lesser.fi, vll())));
		if (x < 0 || x >= vSize) return ans;
		SegT<P<T, ll>> segt(vSize, mp(Lesser.fi, -1), clam(
			if (l.se < 0) return r;
		if (r.se < 0) return l;
		return Lesser.se(l.fi, r.fi) ? l : r;
		));
		segt.set(x, mp(Add.fi, x));
		P<T, ll> now;
		while ((now = segt.que(0, vSize - 1)).se >= 0) {
			ans.se[now.se].fi = segt[now.se].fi;
			ans.fi = Add.se(ans.fi, ans.se[now.se].fi);
			segt.set(now.se, mp(Lesser.fi, -2));
			ROR(adj[now.se], i) {
				if (segt[i.se].se == -2) continue;
				if (segt[i.se].se == -1) {
					segt.set(i.se, i);
					ans.se[i.se].se = { now.se };
					continue;
				}
				if (Lesser.se(i.fi, segt[i.se].fi)) {
					segt.set(i.se, i);
					ans.se[i.se].se = { now.se };
					continue;
				}
				if (Equal.se(i.fi, segt[i.se].fi)) {
					ans.se[i.se].se.pb(now.se);
					continue;
				}
			}
		}
		return ans;
	}

};

template <class T> struct Sum {
public:
	V<T> v, s;
	ll size;
	ActPair(T) Add;
	ActPair(T) Sub;
	Sum(V<T> v, ActPair(T) Add = ADD, ActPair(T) Sub = SUB) : v(v), size(v.sz), Add(Add), Sub(Sub) { Init(); Calc(); }
	void Init() {
		s.asn(size + 1, Add.fi);
	}
	void Calc() {
		REP(i, size) s[i + 1] = Add.se(s[i], v[i]);
	}
	T operator()(ll x) {
		if (x < -1) x = -1;
		if (x > size - 1) x = size - 1;
		return s[x + 1];
	}
	T operator()(ll l, ll r) {
		if (l < 0) l = 0;
		if (r >= size) r = size - 1;
		if (l > r) return Add.fi;
		return Sub.se(s[r + 1], s[l]);
	}
};
using sumll = Sum<ll>;

template <class T> struct Sum2 {
public:
	V<V<T>> v, s;
	ll RowSize, ColumnSize;
	ActPair(T) Add;
	ActPair(T) Sub;
	Sum2(V<V<T>> v, ActPair(T) Add = ADD, ActPair(T) Sub = SUB) : v(v), RowSize(v.sz), ColumnSize(v.sz ? v[0].sz : 0), Add(Add), Sub(Sub) { Init(); Calc(); }
	void Init() {
		s.asn(RowSize + 1, V<T>(ColumnSize + 1, Add.fi));
	}
	void Calc() {
		REP1(r, RowSize) {
			REP1(c, ColumnSize) {
//				s[r][c] = Sub.se(Add.se(Add.se(v[r - 1][c - 1], operator()(r - 1, c - 2)), operator()(r - 2, c - 1)), operator()(r - 2, c - 2));
				s[r][c] = Add.se(s[r][c - 1], v[r - 1][c - 1]);
			}
		}
		REP1(r, RowSize) {
			REP1(c, ColumnSize) {
				s[r][c] = Add.se(s[r - 1][c], s[r][c]);
			}
		}
	}
	T operator()(ll r, ll c) {
		if (r < -1) r = -1;
		if (c < -1) c = -1;
		if (r > RowSize - 1) r = RowSize - 1;
		if (c > ColumnSize - 1) c = ColumnSize - 1;
		return s[r + 1][c + 1];
	}
	T operator()(ll r1, ll c1, ll r2, ll c2) {
		if (r1 < 0) r1 = 0;
		if (c1 < 0) c1 = 0;
		if (r2 >= RowSize) r2 = RowSize - 1;
		if (c2 >= ColumnSize) c2 = ColumnSize - 1;
		if (r1 > r2) return Add.fi;
		if (c1 > c2) return Add.fi;
		return Sub.se(Add.se(s[r2 + 1][c2 + 1], s[r1][c1]), Add.se(s[r2 + 1][c1], s[r1][c2 + 1]));
	}
};
using sumll2 = Sum2<ll>;

template <class T> struct Point2 {
public:
	V<V<T>> v;
	ll h, w;
	Point2() : h(0), w(0) {}
	Point2(ll h, ll w) : h(h), w(w) { asn(h, w); }
	Point2(ll h, ll w, T val) : h(h), w(w) { asn(h, w, val); }
	void assign(ll h, ll w) { v.asn(h, V<T>(w)); }
	void assign(ll h, ll w, ll val) { v.asn(h, V<T>(w, val)); }
	T& operator()(ll h, ll w) { return v[h][w]; }
	T& operator()(pl p) { return v[p.fi][p.se]; }
};
template <class T> using P2 = Point2<T>;

template <ll Mod> struct Modll {
public:
	ll v;
	Modll() : v(0) {}
	Modll(ll _v) { set(_v % Mod + Mod); }
	Modll& set(ll _v) {
		v = (_v < Mod) ? _v : (_v - Mod);
		return *this;
	}
	Modll pow(ll n) const {
		Modll x = *this, ans = 1;
		while (n) {
			if (n & 1) ans *= x;
			x *= x;
			n >>= 1;
		}
		return ans;
	}
	Modll inverse() const { return (*this).pow(Mod - 2); }
	Modll operator+(const Modll& m) const { return Modll().set(v + m.v); }
	Modll operator-(const Modll& m) const { return Modll().set(Mod + v - m.v); }
	Modll operator*(const Modll& m) const { return Modll().set((ull(v) * m.v) % Mod); }
	Modll operator/(const Modll& m) const { return *this * m.inv; }
	Modll& operator+=(const Modll& m) { return *this = *this + m; }
	Modll& operator-=(const Modll& m) { return *this = *this - m; }
	Modll& operator*=(const Modll& m) { return *this = *this * m; }
	Modll& operator/=(const Modll& m) { return *this = *this / m; }
	Modll operator-() const { return Modll(0) - *this; }
	explicit operator bool() const { return v != 0; }
	friend istream& operator>>(istream& in, Modll& m) { return in >> m.v; }
	friend ostream& operator<<(ostream& out, const Modll& m) { return out << m.v; }
};
using mll = Modll<MOD>;
using vmll = V<mll>;
using vvmll = V<vmll>;
using vvvmll = V<vvmll>;

vmll MFactMemo(2, 1);
vmll MIFactMemo(2, 1);

mll mFact(ll n) {
	if (MFactMemo.sz <= n) {
		ll oldsize = MFactMemo.sz;
		MFactMemo.res(n + 1, 1);
		FOR(i, oldsize, n) MFactMemo[i] = MFactMemo[i - 1] * i;
	}
	return MFactMemo[n];
}
mll miFact(ll n) {
	if (MIFactMemo.sz <= n) {
		ll oldsize = MIFactMemo.sz;
		MIFactMemo.res(n + 1, 1);
		MIFactMemo.bk = mFact(n).inv;
		rFOR(i, oldsize + 1, n) MIFactMemo[i - 1] = MIFactMemo[i] * i;
	}
	return MIFactMemo[n];
}
mll mComb(ll n, ll k) {
	if (n < 0 || k < 0 || n < k) return 0;
	return mFact(n) * miFact(k) * miFact(n - k);
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

void PCmprs(vll& v) {
	if (v.sz == 0) return;
	vll vv(v);
	IOTA(vv, 0);
	sort(vv.bgn, vv.en, [&](ll v1, ll v2) {return v[v1] < v[v2]; });
	IOTA(v, 0);
	sort(v.bgn, v.en, [&](ll v1, ll v2) {return vv[v1] < vv[v2]; });
	return;
}

ll BblCnt(vll v) {
	PCmprs(v);
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

template<class T> V<V<T>> MultiMatrix(V<V<T>> A, V<V<T>> B, ActPair(T) Mul = MUL, ActPair(T) Add = ADD) {
	V<V<T>> ans;
	ll ii = A.sz;
	if (!ii) return ans;
	ll jj = A[0].sz;
	if (!jj) return ans;
	ll jj2 = B.sz;
	if (!jj2) return ans;
	if (jj != jj2) return ans;
	ll kk = B[0].sz;
	if (!kk) return ans;
	ans.asn(ii, V<T>(kk, 0));
	REP(i, ii) {
		REP(k, kk) {
			REP(j, jj) {
				ans[i][k] = Add.se(ans[i][k], Mul.se(A[i][j], B[j][k]));
			}
		}
	}
	return ans;
}

vvll CombMemo(1000, vll(1000, -1));

ll Comb(ll n, ll k) {
	if ((n < 0) || (k < 0)) return 0;
	if (CombMemo[n][k] == -1) {
		if (n < k) CombMemo[n][k] = 0;
		else {
			if (n == 0) CombMemo[n][k] = 1;
			else if (k == 0) CombMemo[n][k] = 1;
			else if (n == k) CombMemo[n][k] = 1;
			else CombMemo[n][k] = Comb(n - 1, k - 1) + Comb(n - 1, k);
		}
	}
	return CombMemo[n][k];
}

template<class T> map<T, ll> Dict(V<T> v) {
	map<T, ll> m;
	if (!v.sz) return m;
	SORT(v);
	UNIQUE(v);
	REP(i, v.sz) {
		m[v[i]] = i;
	}
	return m;
}

template<class T> vll Cmprs(V<T> v) {
	auto m = Dict(v);
	vll ans(v.sz);
	REP(i,v.sz) {
		ans[i] = m[v[i]];
	}
	return ans;
}

template <class T> auto ven(T val) { return val; }
template <> auto ven<int>(int val) { return (ll)val; }
template <class T, class... Args> auto ven(T val, Args... args) {
	auto tmp = ven(args...);
	return V<decltype(tmp)>(val, tmp);
}

template <class T> void zind(T& v) { v--; }
template <class T> void zind(V<T>& v) { ROR(v, i) zind(i); }
template <class T, class... Args> void zind(T& v, Args&... args) { zind(v); zind(args...); }

void Solve();

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << setprecision(20) << fixed;
	Solve();
}

void Solve() {

	li(N);
	vpli(N, p);
	vll ju(N);
	IOTA(ju, 0);
	Graph<ll> g(N);
	sort(ju.bgn, ju.en, clam(return p[l].fi < p[r].fi;));
	REP(i, N - 1) g.AddE(ju[i], ju[i + 1], p[ju[i + 1]].fi - p[ju[i]].fi);
	sort(ju.bgn, ju.en, clam(return p[l].se < p[r].se;));
	REP(i, N - 1) g.AddE(ju[i], ju[i + 1], p[ju[i + 1]].se - p[ju[i]].se);
	sal(g.rPrim(0).fi);

}
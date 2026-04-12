#include <bits/stdc++.h>
using namespace std;

template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
template <class T> using VVV = V<VV<T>>;
template <class S, class T> using P = pair<S, T>;
template <class... T> using TP = tuple<T...>;

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
using vvvd = V<vvd>;
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
#define vllin(N,v) vll (v)((N));vin(v);
#define vllin2(N,a,b) vll (a)(N),(b)(N);REP(i,N){cin>>(a)[i]>>(b)[i];};
#define vsin(N,v) vs (v)((N));vin(v);
#define rdn(a,b) ((a)/(b))
#define rou(a,b) ((((double(a)/double(b))-((a)/(b)))<0.5)?((a)/(b)):(((a)/(b))+1))
#define rup(a,b) ((((a)%(b))==0)?((a)/(b)):(((a)/(b))+1))
#define powll(a,b) (ll)(pow((double)(a),(double)(b)))
#define Triangle(x1,y1,x2,y2,x3,y3) (((x1)-(x2))*((y1)-(y3))-((x1)-(x3))*((y1)-(y2)))
#define tg(t,i) get<i>(t)

#define Id(x) get<0>(x)
#define Act(x) get<1>(x)
#define InvAct(x) get<2>(x)
#define mg(id,act) mt(id,act,lam(l))
//#define MonoidSet(T) TP<T, function<T(T, T)>>
#define GroupSet(T) TP<T, function<T(T, T)>, function<T(T, T)>>
#define CompareSet(T) TP<T, function<bool(T, T)>>
#define lam(lr) ([](auto l, auto r){return (lr);})
#define elam(lr) ([=](auto l, auto r){return (lr);})
#define clam(lr) ([&](auto l, auto r){return (lr);})
#define lamr(lr) ([](auto l, auto r){lr})
#define elamr(lr) ([=](auto l, auto r){lr})
#define clamr(lr) ([&](auto l, auto r){lr})
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

template <class T> auto GetVectorValueType(T v) { return v; }
template <class T> auto GetVectorValueType(V<T> v) { return GetVectorValueType(T()); }

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
template <class T, class... Args> void vInit2(ll rowSize, ll columnSize, VV<T>& v, Args&... args) {
	v.asn(rowSize, V<T>(columnSize));
	vInit2(rowSize, columnSize, args...);
}
void vInput2(ll rowSize, ll columnSize) {}
template <class T, class... Args> void vInput2(ll rowSize, ll columnSize, VV<T>& v, Args&... args) {
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
template <class T> void salv(VV<T> v) {
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

/*
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
*/

auto LES = mp(INF, lam(l < r));
auto GRT = mp(-INF, lam(l > r));
auto EQ = mp(0, lam(l == r));

auto ADD = mt(0, lam(l + r), lam(l - r));
auto MUL = mt(1, lam(l * r), lam(l / r));
auto XOR = mt(0, lam(l ^ r), lam(l ^ r));
auto OR = mg(0, lam(l | r));
auto AND = mg(((ll)(1) << 63) - 1, lam(l & r));
auto MIN = mg(0, lam((l < r) ? l : r));
auto MAX = mg(0, lam((l > r) ? l : r));
auto GCD = mg(0, lam(Gcd(l, r)));
auto LCM = mg(0, lam(Lcm(l, r)));

template <class OperationType> auto Operation(OperationType A) { return Id(A); }
template <class OperationType, class T> auto Operation(OperationType A, T x) { return x; }
template <class OperationType, class T, class... Args> auto Operation(OperationType A, T x, Args... args) {
	auto tmp = Operation(A, args...);
	return Act(A)(x, tmp);
}

template <class OperationType> auto VOperation(OperationType A) { return Id(A); }
template <class OperationType, class T> auto VOperation(OperationType A, T x) { return x; }
template <class OperationType, class T> auto VOperation(OperationType A, V<T> v) {
	if (v.emp) {
		decltype(GetVectorValueType(T())) tmp = Id(A);
		return tmp;
	}
	auto tmp = VOperation(A, v[0]);
	FOR(i, 1, v.sz - 1) tmp = Act(A)(tmp, VOperation(A, v[i]));
	return tmp;
}
template <class OperationType, class T, class... Args> auto VOperation(OperationType A, T x, Args... args) {
	auto xResult = VOperation(A, x);
	auto tmp = VOperation(A, args...);
	return Act(A)(xResult, tmp);
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

template <class T> struct pUFT {

public:

	ll tsize;
	ll now;
	vll par;
	vll rank;
	vll mtime;
	vvll sizepi;
	VV<T> sizepv;
	V<T> elm;
	GroupSet(T) Add;

	pUFT(ll tsize, GroupSet(T) Add = ADD) : tsize(tsize), Add(Add) { init(); }
	void init() {
		now = 0;
		par.asn(tsize, -1);
		rank.asn(tsize, 0);
		mtime.asn(tsize, INF);
		sizepi.asn(tsize, { 0 });
		sizepv.asn(tsize, {});
	}
	void set(ll x, T s) {
		elm[x] = s;
		sizepv[x] = { s };
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
				elm[y] = Act(Add)(elm[x], elm[y]);
				sizepi[y].pb(now);
				sizepv[y].pb(elm[y]);
				par[x] = y;
				mtime[x] = now;
			}
			else {
				elm[x] = Act(Add)(elm[x], elm[y]);
				sizepi[x].pb(now);
				sizepv[x].pb(elm[x]);
				par[y] = x;
				mtime[y] = now;
				if (rank[x] == rank[y]) rank[x]++;
			}
		}
		return now;
	}
	T size(ll x, ll t) {
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
			dweight[y] = w;
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

template <class T> struct sUFT {

public:
	ll tsize;
	ll mode;
	vll par;
	vll rank;
	GroupSet(T) Add;
	V<T> elm;
	sUFT(ll tsize, GroupSet(T) Add = ADD, ll mode = 0) : tsize(tsize), Add(Add), mode(mode) { init(); }
	void init() {
		par.asn(tsize, -1);
		if (!mode) rank.res(tsize, 0);
		elm.asn(tsize, Id(Add));
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
			elm[x] = Act(Add)(elm[x], elm[y]);
			par[y] = x;
		}
		else {
			if (rank[x] < rank[y]) {
				elm[y] = Act(Add)(elm[x], elm[y]);
				par[x] = y;
			}
			else {
				elm[x] = Act(Add)(elm[x], elm[y]);
				par[y] = x;
				if (rank[x] == rank[y]) rank[x]++;
			}
		}
	}
	T size(ll x) {
		return elm[root(x)];
	}
	T& operator[](ll x) { return elm[x]; }
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
	GroupSet(T) Add;
	CompareSet(T) Less;
	CompareSet(T) Equal;
	VV<P<T, ll>> adj;
	map<pl, T> len;
	Graph(ll vSize, ll eMode = 0, ll mapMode = 0, GroupSet(T) Add = ADD, CompareSet(T) Less = LES, CompareSet(T) Equal = EQ) : vSize(vSize), eMode(eMode), mapMode(mapMode), Add(Add), Less(Less), Equal(Equal) {}
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
		if (!len.count(mp(x, y))) return mp(false, Id(Less));
		return mp(true, len[mp(x, y)]);
	}
	V<T> Dijk(ll x) {
		V<T> ans(vSize, Id(Less));
		if (x < 0 || x >= vSize) return ans;
		SegT<P<T, ll>> segt(vSize, mp(Id(Less), -1), clamr(
			if (l.se < 0) return r;
		if (r.se < 0) return l;
		return Act(Less)(l.fi, r.fi) ? l : r;
		));
		segt.set(x, mp(Id(Add), x));
		P<T, ll> now;
		while ((now = segt.que(0, vSize - 1)).se >= 0) {
			ans[now.se] = segt[now.se].fi;
			segt.set(now.se, mp(Id(Less), -2));
			ROR(adj[now.se], i) {
				if (segt[i.se].se == -2) continue;
				if (segt[i.se].se == -1) {
					segt.set(i.se, mp(Act(Add)(ans[now.se], i.fi), i.se));
					continue;
				}
				if (Act(Less)(Act(Add)(ans[now.se], i.fi), segt[i.se].fi)) {
					segt.set(i.se, mp(Act(Add)(ans[now.se], i.fi), i.se));
					continue;
				}
			}
		}
		return ans;
	}
	V<P<T, vll>> rDijk(ll x) {
		V<P<T, vll>> ans(vSize, mp(Id(Less), vll()));
		if (x < 0 || x >= vSize) return ans;
		SegT<P<T, ll>> segt(vSize, mp(Id(Less), -1), clamr(
			if (l.se < 0) return r;
		if (r.se < 0) return l;
		return Act(Less)(l.fi, r.fi) ? l : r;
		));
		segt.set(x, mp(Id(Add), x));
		P<T, ll> now;
		while ((now = segt.que(0, vSize - 1)).se >= 0) {
			ans[now.se].fi = segt[now.se].fi;
			segt.set(now.se, mp(Id(Less), -2));
			ROR(adj[now.se], i) {
				if (segt[i.se].se == -2) continue;
				if (segt[i.se].se == -1) {
					segt.set(i.se, mp(Act(Add)(ans[now.se].fi, i.fi), i.se));
					ans[i.se].se = { now.se };
					continue;
				}
				if (Act(Less)(Act(Add)(ans[now.se].fi, i.fi), segt[i.se].fi)) {
					segt.set(i.se, mp(Act(Add)(ans[now.se].fi, i.fi), i.se));
					ans[i.se].se = { now.se };
					continue;
				}
				if (Act(Equal)(Act(Add)(ans[now.se].fi, i.fi), segt[i.se].fi)) {
					ans[i.se].se.pb(now.se);
					continue;
				}
			}
		}
		return ans;
	}

	T Prim(ll x = 0) {
		T ans = Id(Add);
		if (x < 0 || x >= vSize) return ans;
		SegT<P<T, ll>> segt(vSize, mp(Id(Less), -1), clamr(
			if (l.se < 0) return r;
		if (r.se < 0) return l;
		return Act(Less)(l.fi, r.fi) ? l : r;
		));
		segt.set(x, mp(Id(Add), x));
		P<T, ll> now;
		while ((now = segt.que(0, vSize - 1)).se >= 0) {
			ans = Act(Add)(ans, segt[now.se].fi);
			segt.set(now.se, mp(Id(Less), -2));
			ROR(adj[now.se], i) {
				if (segt[i.se].se == -2) continue;
				if (segt[i.se].se == -1) {
					segt.set(i.se, i);
					continue;
				}
				if (Act(Less)(i.fi, segt[i.se].fi)) {
					segt.set(i.se, i);
					continue;
				}
			}
		}
		return ans;
	}

	P<T, V<P<T, vll>>> rPrim(ll x = 0) {
		P<T, V<P<T, vll>>> ans = mp(Id(Add), V<P<T, vll>>(vSize, mp(Id(Less), vll())));
		if (x < 0 || x >= vSize) return ans;
		SegT<P<T, ll>> segt(vSize, mp(Id(Less), -1), clamr(
			if (l.se < 0) return r;
		if (r.se < 0) return l;
		return Act(Less)(l.fi, r.fi) ? l : r;
		));
		segt.set(x, mp(Id(Add), x));
		P<T, ll> now;
		while ((now = segt.que(0, vSize - 1)).se >= 0) {
			ans.se[now.se].fi = segt[now.se].fi;
			ans.fi = Act(Add)(ans.fi, ans.se[now.se].fi);
			segt.set(now.se, mp(Id(Less), -2));
			ROR(adj[now.se], i) {
				if (segt[i.se].se == -2) continue;
				if (segt[i.se].se == -1) {
					segt.set(i.se, i);
					ans.se[i.se].se = { now.se };
					continue;
				}
				if (Act(Less)(i.fi, segt[i.se].fi)) {
					segt.set(i.se, i);
					ans.se[i.se].se = { now.se };
					continue;
				}
				if (Act(Equal)(i.fi, segt[i.se].fi)) {
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
	GroupSet(T) Add;
	Sum(V<T> v, GroupSet(T) Add = ADD) : v(v), size(v.sz), Add(Add) { Init(); Calc(); }
	void Init() {
		s.asn(size + 1, Id(Add));
	}
	void Calc() {
		REP(i, size) s[i + 1] = Act(Add)(s[i], v[i]);
	}
	T operator()(ll x) {
		if (x < -1) x = -1;
		if (x > size - 1) x = size - 1;
		return s[x + 1];
	}
	T operator()(ll l, ll r) {
		if (l < 0) l = 0;
		if (r >= size) r = size - 1;
		if (l > r) return Id(Add);
		return InvAct(Add)(s[r + 1], s[l]);
	}
};
using sumll = Sum<ll>;

template <class T> struct Sum2 {
public:
	VV<T> v, s;
	ll RowSize, ColumnSize;
	GroupSet(T) Add;
	Sum2(VV<T> v, GroupSet(T) Add = ADD) : v(v), RowSize(v.sz), ColumnSize(v.sz ? v[0].sz : 0), Add(Add) { Init(); Calc(); }
	void Init() {
		s.asn(RowSize + 1, V<T>(ColumnSize + 1, Id(Add)));
	}
	void Calc() {
		REP1(r, RowSize) {
			REP1(c, ColumnSize) {
//				s[r][c] = InvAct(Add)(Act(Add)(Act(Add)(v[r - 1][c - 1], operator()(r - 1, c - 2)), operator()(r - 2, c - 1)), operator()(r - 2, c - 2));
				s[r][c] = Act(Add)(s[r][c - 1], v[r - 1][c - 1]);
			}
		}
		REP1(r, RowSize) {
			REP1(c, ColumnSize) {
				s[r][c] = Act(Add)(s[r - 1][c], s[r][c]);
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
		if (r1 > r2) return Id(Add);
		if (c1 > c2) return Id(Add);
		return InvAct(Add)(Act(Add)(s[r2 + 1][c2 + 1], s[r1][c1]), Act(Add)(s[r2 + 1][c1], s[r1][c2 + 1]));
	}
};
using sumll2 = Sum2<ll>;

template <class T> struct Point2 {
public:
	VV<T> v;
	ll h, w;
	Point2() : h(0), w(0) {}
	Point2(ll h, ll w) : h(h), w(w) { asn(h, w); }
	Point2(ll h, ll w, T val) : h(h), w(w) { asn(h, w, val); }
	Point2(VV<T> cv) : h(cv.sz), w(cv.sz ? cv[0].sz : 0) { asn(h, w); copy(cv); }
	void assign(ll h, ll w) { v.asn(h, V<T>(w)); }
	void assign(ll h, ll w, ll val) { v.asn(h, V<T>(w, val)); }
	void copy(VV<T> cv) { REP(_h, h) REP(_w, w) v[_h][_w] = cv[_h][_w]; }
	T& operator()(ll h, ll w) { return v[h][w]; }
	T& operator()(pl p) { return v[p.fi][p.se]; }
	T& operator[](pl p) { return v[p.fi][p.se]; }
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

ll Bsrch(function<bool(ll x)> f, ll mi, ll ma) {
	ll ng = mi - 1, ok = ma, mid;
	while (ok - ng > 1) {
		mid = (ng + ok) / 2;
		(f(mid) ? ok : ng) = mid;
	}
	return ok;
}

template <class T, class M = decltype(MUL), class S = decltype(ADD)> VV<T> MultiMatrix(VV<T> A, VV<T> B, M Mul = MUL, S Add = ADD) {
	VV<T> ans;
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
				ans[i][k] = Act(Add)(ans[i][k], Act(Mul)(A[i][j], B[j][k]));
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

template <class T> vll Cmprs(V<T> v) {
	auto m = Dict(v);
	vll ans(v.sz);
	REP(i,v.sz) {
		ans[i] = m[v[i]];
	}
	return ans;
}

template <class T> vll PCmprs(V<T> v) {
	if (v.sz == 0) return V<T>();
	vll tmp(v.sz);
	vll ans(v.sz);
	IOTA(tmp, 0);
	IOTA(ans, 0);
	sort(tmp.bgn, tmp.en, clam(v[l] < v[r]));
	sort(ans.bgn, ans.en, clam(tmp[l] < tmp[r]));
	return ans;
}

ll BblCnt(vll rv) {
	vll v = PCmprs(rv);
	SegT<ll> b(v.sz, 0);
	ll ans = 0;
	REP(i, v.sz) {
		ans += (i - b.que(0, v[i]));
		b.add(v[i], 1);
	}
	return ans;
}

pl NGrid(pl p, ll i, ll H, ll W) {
	p = mp(p.fi + DX[i], p.se + DY[i]);
	if (p.fi < 0 || p.fi >= H || p.se < 0 || p.se >= W) return mp(INF, INF);
	return p;
}

vvll llGrid(vs v) {
	vvll r(v.sz, vll(v.sz ? v[0].sz : 0, 0));
	REP(h, v.sz) REP(w, v.sz ? v[0].sz : 0) r[h][w] = (v[h][w] == '#');
	return r;
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

template<class S, class T> void SORTby(V<S>& i, const V<T>& x) {
	sort(i.bgn, i.en, clam(x[l] < x[r]));
}
template<class S, class T> void rSORTby(V<S>& i, const V<T>& x) {
	sort(i.bgn, i.en, clam(x[l] > x[r]));
}

template< typename Monoid, typename OperatorMonoid = Monoid >
struct LazySegmentTree
{
	using F = function< Monoid(Monoid, Monoid) >;
	using G = function< Monoid(Monoid, OperatorMonoid) >;
	using H = function< OperatorMonoid(OperatorMonoid, OperatorMonoid) >;
	using P = function< OperatorMonoid(OperatorMonoid, ll) >;

	ll size;
	vector< Monoid > data;
	vector< OperatorMonoid > lazy;
	const F f;
	const G g;
	const H h;
	const P p;
	const Monoid M1;
	const OperatorMonoid OM0;


	LazySegmentTree(ll n, const F f, const G g, const H h, const P p,
		const Monoid &M1, const OperatorMonoid OM0)
		: f(f), g(g), h(h), p(p), M1(M1), OM0(OM0)
	{
		size = 1;
		while (size < n) size <<= 1;
		data.assign(2 * size, M1);
		lazy.assign(2 * size, OM0);
	}

	void set(ll k, const Monoid &x)
	{
		data[k + size] = x;
	}

	void build()
	{
		for (ll k = size - 1; k > 0; k--) {
			data[k] = f(data[2 * k + 0], data[2 * k + 1]);
		}
	}

	void propagate(ll k, ll len)
	{
		if (lazy[k] != OM0) {
			if (k < size) {
				lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);
				lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
			}
			data[k] = g(data[k], p(lazy[k], len));
			lazy[k] = OM0;
		}
	}

	Monoid update(ll a, ll b, const OperatorMonoid &x, ll k, ll l, ll r)
	{
		propagate(k, r - l);
		if (r <= a || b <= l) {
			return data[k];
		}
		else if (a <= l && r <= b) {
			lazy[k] = h(lazy[k], x);
			propagate(k, r - l);
			return data[k];
		}
		else {
			return data[k] = f(update(a, b, x, 2 * k + 0, l, (l + r) >> 1),
				update(a, b, x, 2 * k + 1, (l + r) >> 1, r));
		}
	}

	Monoid update(ll a, ll b, const OperatorMonoid &x)
	{
		return update(a, b, x, 1, 0, size);
	}


	Monoid query(ll a, ll b, ll k, ll l, ll r)
	{
		propagate(k, r - l);
		if (r <= a || b <= l) {
			return M1;
		}
		else if (a <= l && r <= b) {
			return data[k];
		}
		else {
			return f(query(a, b, 2 * k + 0, l, (l + r) >> 1),
				query(a, b, 2 * k + 1, (l + r) >> 1, r));
		}
	}

	Monoid query(ll a, ll b)
	{
		return query(a, b, 1, 0, size);
	}

	Monoid operator[](const ll &k)
	{
		return query(k, k + 1);
	}
};

void Solve();

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << setprecision(20) << fixed;
	Solve();
}

void Solve() {

	li(N);
	vli(N, H);
	ll ans = 0, ma = 0;
	REP(i, N) {
		if (H[i] >= ma) ans++;
		emax(ma, H[i]);
	}
	sal(ans);

}
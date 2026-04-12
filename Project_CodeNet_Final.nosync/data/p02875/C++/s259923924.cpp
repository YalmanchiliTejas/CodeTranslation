#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){
	return o<<"("<<p.fs<<","<<p.sc<<")";
}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){
	o<<"{";
	for(const T& v:vc) o<<v<<",";
	o<<"}";
	return o;
}
using ll = long long;
template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

#ifdef LOCAL
#define show(x) cerr << "LINE" << __LINE__ << " : " << #x << " = " << (x) << endl
#define dump(x) cerr << "LINE" << __LINE__ << " : " << #x << " = {";  \
	for(auto DUMMY: x) cerr << DUMMY << ","; cerr << "}" << endl;
#else
#define show(x) true
#define dump(x) true
#endif

template<unsigned int mod_>
struct ModInt{
	using uint = unsigned int;
	using ll = long long;
	using ull = unsigned long long;

	constexpr static uint mod = mod_;

	uint v;
	ModInt():v(0){}
	ModInt(ll _v):v(normS(_v%mod+mod)){}
	explicit operator bool() const {return v!=0;}
	static uint normS(const uint &x){return (x<mod)?x:x-mod;}		// [0 , 2*mod-1] -> [0 , mod-1]
	static ModInt make(const uint &x){ModInt m; m.v=x; return m;}
	ModInt operator+(const ModInt& b) const { return make(normS(v+b.v));}
	ModInt operator-(const ModInt& b) const { return make(normS(v+mod-b.v));}
	ModInt operator-() const { return make(normS(mod-v)); }
	ModInt operator*(const ModInt& b) const { return make((ull)v*b.v%mod);}
	ModInt operator/(const ModInt& b) const { return *this*b.inv();}
	ModInt& operator+=(const ModInt& b){ return *this=*this+b;}
	ModInt& operator-=(const ModInt& b){ return *this=*this-b;}
	ModInt& operator*=(const ModInt& b){ return *this=*this*b;}
	ModInt& operator/=(const ModInt& b){ return *this=*this/b;}
	ModInt& operator++(int){ return *this=*this+1;}
	ModInt& operator--(int){ return *this=*this-1;}
	ll extgcd(ll a,ll b,ll &x,ll &y) const{
		ll p[]={a,1,0},q[]={b,0,1};
		while(*q){
			ll t=*p/ *q;
			rep(i,3) swap(p[i]-=t*q[i],q[i]);
		}
		if(p[0]<0) rep(i,3) p[i]=-p[i];
		x=p[1],y=p[2];
		return p[0];
	}
	ModInt inv() const {
		ll x,y;
		extgcd(v,mod,x,y);
		return make(normS(x+mod));
	}
	ModInt pow(ll p) const {
		if(p<0) return inv().pow(-p);
		ModInt a = 1;
		ModInt x = *this;
		while(p){
			if(p&1) a *= x;
			x *= x;
			p >>= 1;
		}
		return a;
	}
	bool operator==(const ModInt& b) const { return v==b.v;}
	bool operator!=(const ModInt& b) const { return v!=b.v;}
	friend istream& operator>>(istream &o,ModInt& x){
		ll tmp;
		o>>tmp;
		x=ModInt(tmp);
		return o;
	}
	friend ostream& operator<<(ostream &o,const ModInt& x){ return o<<x.v;}
};
using mint = ModInt<998244353>;


vector<mint> extended(int n, const vector< vector<mint> >& coeffs, const vector<mint>& terms) {

	vector<mint> ret(max<int>(n + 1, terms.size()));
	copy(terms.begin(), terms.end(), ret.begin());
	const int order = coeffs.size() - 1;
	const int deg = coeffs[0].size() - 1;
	assert((int) terms.size() >= order);
	for (int m = terms.size(); m <= n; ++m) {
		mint s = 0;
		for (int i = 1; i <= order; ++i) {
			int k = m - i;
			mint t = ret[k];
			for (int d = 0; d <= deg; ++d) {
				s += t * coeffs[i][d];
				t *= k;
			}
		}
		mint denom = 0, mpow = 1;
		for (int d = 0; d <= deg; ++d) {
			denom += mpow * coeffs[0][d];
			mpow *= m;
		}
		ret[m] = -s/denom;
	}
	return ret;
}

vector< vector<mint> > find_recurrence_relation(vector<mint> terms, int deg, int ord = -1, bool verify=true) {

	if(ord != -1){		//given order
		int n = (deg+1)*(ord+1)+ord-1;
		while((int)terms.size()>n) terms.pop_back();
	}

	const int n = terms.size();
	const int B = (n + 2) / (deg + 2); // number of blocks
	const int C = B * (deg + 1); // number of columns
	const int R = n - (B - 1); // number of rows
	assert(B >= 2); assert(R >= C - 1);

	auto error = [] (int order, int deg) {
		fprintf(stderr, 
			"Error: Could not find a recurrence relation "
			"of order <= %d and degree <= %d.\n\n", 
			order, deg);
		assert(0);
	};

	vector< vector<mint> > mat(R, vector<mint>(C));
	for (int y = 0; y < R; ++y) {
		for (int b = 0; b < B; ++b) {
			mint v = terms[y+b];
			for (int d = 0; d <= deg; ++d) {
				mat[y][b * (deg + 1) + d] = v;
				v *= y+b;
			}
		}
	}

	int rank = 0;
	for (int x = 0; x < C; ++x) {
		int pivot = -1;
		for (int y = rank; y < R; ++y) if (mat[y][x] != 0) {
			pivot = y; break;
		}
		if (pivot < 0) break;
		if (pivot != rank) swap(mat[rank], mat[pivot]);
		mint inv = mat[rank][x].inv();
		for (int x2 = x; x2 < C; ++x2) mat[rank][x2] *= inv;
		for (int y = rank + 1; y < R; ++y) if (mat[y][x]) {
			mint c = -mat[y][x];
			for (int x2 = x; x2 < C; ++x2) {
				mat[y][x2] += c * mat[rank][x2];
			}
		}
		++rank;
	}

	if (rank == C) error(B - 1, deg);

	for (int y = rank - 1; y >= 0; --y) if (mat[y][rank]) {
		assert(mat[y][y] == 1);
		mint c = -mat[y][rank];
		for (int y2 = 0; y2 < y; ++y2) {
			mat[y2][rank] += c * mat[y2][y];
		}
	}

	int order = rank / (deg + 1);

	vector< vector<mint> > ret(order + 1, vector<mint>(deg + 1));
	ret[0][rank % (deg + 1)] = 1;
	for (int y = rank - 1; y >= 0; --y) {
		int k = order - y / (deg + 1), d = y % (deg + 1);
		ret[k][d] = -mat[y][rank];
	}

	if (verify) {
		auto extended_terms = extended(n - 1, ret, 
				vector<mint>(terms.begin(), terms.begin() + order));
		for (int i = 0; i < (int) terms.size(); ++i) {
			if (terms[i] != extended_terms[i]) error(B - 1, deg);
		}
	}

	auto verbose = [&] {
		int last = verify ? n - 1 : order + R - 1;
		fprintf(stderr, 
			"[ Found a recurrence relation ]\n"
			"- order %d\n"
			"- degree %d\n"
			"- verified up to a(%d) (number of non-trivial terms: %d)\n",
			order, deg, last, (last + 1) - ((deg + 2) * (order + 1) - 2)
		);
		fprintf(stderr, "{\n");
		for (int k = 0; k <= order; ++k) {
			fprintf(stderr, "  {");
			for (int d = 0; d <= deg; ++d) {
				if (d) fprintf(stderr, ", ");
				fprintf(stderr, "%d", ret[k][d].v);
			}
			fprintf(stderr, "}%s\n", k == order ? "" : ",");
		}
		fprintf(stderr, "}\n\n");
	};
	verbose();

	return ret;
}

void show_extended_sequence(int n, const vector<mint>& terms, int degree, int order = -1) {
	auto coeffs = find_recurrence_relation(terms, degree, order);
	auto extended_terms = extended(n, coeffs, terms);
	for (int i = 0; i < (int) extended_terms.size(); ++i) {
		printf("%d %d\n", i, extended_terms[i].v);
	}
	puts("");
}
V<mint> get_extended_sequence(int n, const vector<mint>& terms, int degree, int order = -1) {
	auto coeffs = find_recurrence_relation(terms, degree, order);
	return extended(n, coeffs, terms);
}

V<mint> fact,ifact;
mint Choose(int a,int b){
	if(b<0 || a<b) return 0;
	return fact[a] * ifact[b] * ifact[a-b];
}
void InitFact(int N){
	fact.resize(N);
	ifact.resize(N);
	fact[0] = 1;
	rep1(i,N-1) fact[i] = fact[i-1] * i;
	ifact[N-1] = fact[N-1].inv();
	for(int i=N-2;i>=0;i--) ifact[i] = ifact[i+1] * (i+1);
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);		//DON'T USE scanf/printf/puts !!
	cout << fixed << setprecision(20);
	InitFact(1000000);
	
	V<mint> v;
	rep1(N,30){
		mint res = 0;
		rep(a,N+1) rep(b,N+1-a){
			int c = N-a-b;
			rep(x,N+1) rep(y,N+1-x){
				int z = N-x-y;
				if(-c <= a-x && a-x <= z){
					res += fact[N] * ifact[a] * ifact[b] * ifact[c] * fact[N] * ifact[x] * ifact[y] * ifact[z];
				}
			}
		}
		v.pb(res);
	}
	dump(v);
	int N; cin >> N;
	show(get_extended_sequence(100,v,1));
	cout << get_extended_sequence(N/2-1,v,1)[N/2-1] << endl;
}

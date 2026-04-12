#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define debug cerr << "-- " << __LINE__ << " --" << endl
#define MOD 1000000007
#define ALL(o) (o).begin(), (o).end()
typedef long long int ll;
typedef unsigned long long ull;

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
template <typename T> string to_string(const vector<T> &xs) {string s="["; for(int i=0;i<xs.size();i++) s += (i>0 ? " " : "") + to_string(xs[i]); return s + "]";}
template <typename T> ll argmax(const T &xs) {return distance(xs.begin(), max_element(xs.begin(), xs.end()));}
template <typename T> ll argmin(const T &xs) {return distance(xs.begin(), min_element(xs.begin(), xs.end()));}
ll nextLL(){ll x; scanf("%lld", &x); return x;}
int nextInt(){int x; scanf("%d", &x); return x;}
string nextString(){string s; cin >> s; return s;}


ll extgcd(ll a, ll b, ll &x, ll &y) {
    /* g を返す時点で ax + by == g となる */
    ll g = a; x = 1; y = 0;
    if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g;
}
ll gcd(ll a, ll b) { ll x, y; return extgcd(a, b, x, y); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

ll remainder(ll x, ll y) {assert(y > 0); ll r = x % y; if (r < 0) r += y; return r;}
ll quotient(ll x, ll y) {assert(y > 0); return (x - remainder(x, y)) / y;}

class llm{
	ll n;
public:
	llm(){n = 0;}
	llm(ll n){this->n = (n >= 0) ? (n % MOD) : (MOD - 1 - (-n-1 % MOD));}
	operator ll() const {return n;}
	llm operator+(const llm &y) const{ return llm((ll)*this + (ll)y);}
	llm operator+=(const llm &y) { *this = *this + y; return *this;}
	llm operator-(const llm &y) const{ return llm((ll)*this - (ll)y);}
	llm operator-=(const llm &y) { *this = *this - y; return *this;}
	llm operator-() const{ return llm(0) - *this;}
	llm operator*(const llm &y) const{ return llm((ll)*this * (ll)y);}
	llm operator*=(const llm &y) { *this = *this * y; return *this;}
	llm operator/(const llm &y) const{ return *this * y.inv();}
	llm operator/=(const llm &y) { *this = *this / y; return *this;}
	llm inv() const{
		ll x, y;
		if (extgcd(n, MOD, x, y) == 1) return llm(x);
  		return llm(0); // unsolvable
	}
	friend istream& operator >> (istream& os, llm& x);
	friend ostream& operator << (ostream& os, const llm& x);
};
istream& operator >> (istream& is, llm& x){ll n; is >> n; x = llm(n); return is;}
ostream& operator << (ostream& os, const llm& x){os << (ll)x; return os;}

template<typename T> T comb(ll n, ll k){
	T ret = 1;
	for(ll i=1;i<=k;i++) ret = ret * T(n - k + i) / T(i);
	return ret;
}

ull n;
ull s[512], t[512], u[512], v[512];


ll solve(vector<vector<ull>> &ans, const vector<ull> &s, const vector<ull> &t, const vector<ull> &u, const vector<ull> &v){
	ll row[4] = {0}, col[4] = {0};
	for(ll i=0;i<n;i++) row[s[i]*2+t[i]]++;
	for(ll i=0;i<n;i++) col[u[i]*2+v[i]]++;

	vector<ull> flgrow0(n), flgcol0(n), flgrow1(n), flgcol1(n);
	vector<ull> therow0, thecol0, therow1, thecol1;

	for(ll i=0;i<n;i++){
		ll rowcmd = s[i]*2+t[i];
		for(ll j=0;j<n;j++){
			ll colcmd = u[j]*2+v[j];
			if (rowcmd==0){
				if (colcmd==0){
					ans[i][j] = 0;
				}else if (colcmd==1){
					ans[i][j] = 1;
				}else if (colcmd==2){
					ans[i][j] = 0;
				}else if (colcmd==3){
					if (col[0]+col[2]>0) ans[i][j] = 1;
					else if (row[1]+row[3]>0) ans[i][j] = 0;
					else {
						flgrow0[i] = 1;
						flgcol0[j] = 1;
					}
				}
			}else if (rowcmd==1){
				if (colcmd==0){
					ans[i][j] = 1;
				}else if (colcmd==1){
					ans[i][j] = 1;
				}else if (colcmd==2){
					// cerr << "ouch" << endl;
					return -1;
				}else if (colcmd==3){
					ans[i][j] = 1;
				}
			}else if (rowcmd==2){
				if (colcmd==0){
					ans[i][j] = 0;
				}else if (colcmd==1){
					// cerr << "piyo" << endl;
					return -1;
				}else if (colcmd==2){
					ans[i][j] = 0;
				}else if (colcmd==3){
					ans[i][j] = 0;
				}
			}else if (rowcmd==3){
				if (colcmd==0){
					if (row[0]+row[2]>0) ans[i][j] = 1;
					else if (col[1]+col[3]>0) ans[i][j] = 0;
					else {
						flgrow1[i] = 1;
						flgcol1[j] = 1;
					}
				}else if (colcmd==1){
					ans[i][j] = 1;
				}else if (colcmd==2){
					ans[i][j] = 0;
				}else if (colcmd==3){
					ans[i][j] = 1;
				}
			}
		}
	}

	for(ll i=0;i<n;i++) if (flgrow0[i]) therow0.pb(i);
	for(ll i=0;i<n;i++) if (flgcol0[i]) thecol0.pb(i);
	for(ll i=0;i<n;i++) if (flgrow1[i]) therow1.pb(i);
	for(ll i=0;i<n;i++) if (flgcol1[i]) thecol1.pb(i);

	for(ll i=0;i<therow0.size();i++){
		for(ll j=0;j<thecol0.size();j++){
			ans[therow0[i]][thecol0[j]] = (i + j) % 2;
		}
	}
	for(ll i=0;i<therow1.size();i++){
		for(ll j=0;j<thecol1.size();j++){
			ans[therow1[i]][thecol1[j]] = (i + j) % 2;
		}
	}	

	// cerr << "constructed" << endl;
	/*
	for(ll i=0;i<n;i++){
		if (s[i]==0){
			ll val = 1;
			for(ll j=0;j<n;j++) val &= ans[i][j];
			if (val != t[i]) return -1;
		}else{
			ll val = 0;
			for(ll j=0;j<n;j++) val |= ans[i][j];
			if (val != t[i]) return -1;
		}
	}
	for(ll j=0;j<n;j++){
		if (u[j]==0){
			ll val = 1;
			for(ll i=0;i<n;i++) val &= ans[i][j];
			if (val != v[j]) return -1;
		}else{
			ll val = 0;
			for(ll i=0;i<n;i++) val |= ans[i][j];
			if (val != v[j]) return -1;
		}
	}	
	*/
	return 0;
}


int main(void){
	cin >> n;
	for(ull i=0;i<n;i++) cin >> s[i];
	for(ull i=0;i<n;i++) cin >> u[i];
	for(ull i=0;i<n;i++) cin >> t[i];
	for(ull i=0;i<n;i++) cin >> v[i];

	/*
	srand(time(NULL));
	n = 500;
	for(ull i=0;i<n;i++) s[i] = rand()%2;
	for(ull i=0;i<n;i++) u[i] = rand()%2;
	for(ull i=0;i<n;i++) t[i] = rand();
	for(ull i=0;i<n;i++) v[i] = rand();
	*/

	vector<vector<ull>> ans(n, vector<ull>(n));
	vector<vector<ull>> buf(n, vector<ull>(n));
	vector<ull> si(n), ti(n), ui(n), vi(n);	

	for(ull h=0;h<64;h++){
		ull base = (1ULL<<h);
		for(ll i=0;i<n;i++){
			si[i] = s[i];
			ti[i] = ((t[i]&base) > 0);
			ui[i] = u[i];
			vi[i] = ((v[i]&base) > 0);
		}
		// cerr << "------------" << endl;
		// cerr << to_string(si) << endl;
		// cerr << to_string(ti) << endl;
		// cerr << to_string(ui) << endl;
		// cerr << to_string(vi) << endl;
		ll rslt = solve(buf, si, ti, ui, vi);
		// cerr << rslt << endl;
		// cerr << "-------" << endl;

		if (rslt == -1){
			cout << -1 << endl;
			return 0;
		}
		for(ll i=0;i<n;i++)for(ll j=0;j<n;j++) if (buf[i][j]) ans[i][j] |= base;
	}

	

	for(ll i=0;i<n;i++){
		if (s[i]==0){
			ull val = ULLONG_MAX;
			for(ll j=0;j<n;j++) val &= ans[i][j];
			if (val != t[i]) {cout << -1 << endl; return 0;}
		}else{
			ull val = 0;
			for(ll j=0;j<n;j++) val |= ans[i][j];
			if (val != t[i]) {cout << -1 << endl; return 0;}
		}
	}
	for(ll j=0;j<n;j++){
		if (u[j]==0){
			ull val = ULLONG_MAX;
			for(ll i=0;i<n;i++) val &= ans[i][j];
			if (val != v[j]) {cout << -1 << endl; return 0;}
		}else{
			ull val = 0;
			for(ll i=0;i<n;i++) val |= ans[i][j];
			if (val != v[j]) {cout << -1 << endl; return 0;}
		}
	}	


	
	for(ull i=0;i<n;i++){
		for(ull j=0;j<n;j++){
			printf("%llu", ans[i][j]);
			if (j+1<n) printf(" "); else printf("\n");
		}
	}

    return 0;
}



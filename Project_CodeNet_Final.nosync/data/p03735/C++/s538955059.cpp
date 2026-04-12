#include <iostream>
#include <fstream>
#include <cmath>  
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string> 
#include <vector>
#include <bitset>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <random>


using namespace std;
using ll = long long;
using ull = unsigned long long;

#define REP(i,n) for(long long i = 0; i < (n); i++)
#define FOR(i, m, n) for(long long i = (m);i < (n); ++i)
#define ALL(obj) (obj).begin(),(obj).end()

template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;

const ll MOD = (ll)1e9 + 7;
const ll MOD2 = 998244353;
const ll LLINF = (ll)1e18;
const ll INTINF = (ll)1e9;
const long double PI = 3.1415926535897932384626433;

template <class T> void corner(bool flg, T hoge) { if (flg) { cout << hoge << endl; exit(0); } }
template <class T, class U>ostream &operator<<(ostream &o, const map<T, U>&obj) { o << "{"; for (auto &x : obj) o << " {" << x.first << " : " << x.second << "}" << ","; o << " }"; return o; }
template <class T>ostream &operator<<(ostream &o, const set<T>&obj) { o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o; }
template <class T>ostream &operator<<(ostream &o, const vector<T>&obj) { o << "{"; for (int i = 0; i < (int)obj.size(); ++i)o << (i > 0 ? ", " : "") << obj[i]; o << "}"; return o; }
template <class T, class U>ostream &operator<<(ostream &o, const pair<T, U>&obj) { o << "{" << obj.first << ", " << obj.second << "}"; return o; }
template <template <class tmp>  class T, class U> ostream &operator<<(ostream &o, const T<U> &obj) { o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr)o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o; }
void print(void) { cout << endl; }
template <class Head> void print(Head&& head) { cout << head; print(); }
template <class Head, class... Tail> void print(Head&& head, Tail&&... tail) { cout << head << " "; print(forward<Tail>(tail)...); }
template <class T> void chmax(T& a, const T b) { a = max<T>(a, b); }
template <class T> void chmin(T& a, const T b) { a = min<T>(a, b); }
void YN(bool flg) { cout << ((flg) ? "YES" : "NO") << endl; }
void Yn(bool flg) { cout << ((flg) ? "Yes" : "No") << endl; }
void yn(bool flg) { cout << ((flg) ? "yes" : "no") << endl; }

int main() {
	int N; cin >> N;
	V<ll> x(N), y(N);
	for (int i = 0; i < N; ++i) cin >> x[i] >> y[i];
	for (int i = 0; i < N; ++i) if (x[i] > y[i]) swap(x[i], y[i]);
	ll Rmax, Rmin, Bmax, Bmin, ans;
	Rmax = 0, Rmin = LLINF, Bmax = 0, Bmin = LLINF;
	for (int i = 0; i < N; ++i) chmax(Rmax, x[i]);
	for (int i = 0; i < N; ++i) chmin(Rmin, x[i]);
	for (int i = 0; i < N; ++i) chmax(Bmax, y[i]);
	for (int i = 0; i < N; ++i) chmin(Bmin, y[i]);
	ans = (Rmax - Rmin)*(Bmax - Bmin);
	V<P<ll, int>> ord(N);
	for (int i = 0; i < N; ++i) ord[i] = { x[i],i };
	sort(ALL(ord));
	multiset<ll> stR, stB;
	for (int i = 0; i < N; ++i) stR.insert(x[i]);
	for (int i = 0; i < N; ++i) stB.insert(y[i]);
	for (int i = 0; i < N; ++i) {
		ll s = x[ord[i].second], t = y[ord[i].second];
		stR.erase(stR.find(s));
		stB.erase(stB.find(t));
		stR.insert(t);
		stB.insert(s);
		ll cnt = (*stR.rbegin() - *stR.begin())*(*stB.rbegin() - *stB.begin());
		chmin(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}


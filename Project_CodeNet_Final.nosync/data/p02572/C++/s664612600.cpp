// #define _GLIBCXX_DEBUG
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
using ll = long long; using pii = pair<int, int>; using vi = vector<int>; using vvi = vector<vi>; using vl = vector<ll>; using vvl = vector<vl>;
#define rep0(TMS) for (int CNT = 0; CNT < (int)(TMS); CNT++)
#define rep(CNT, GOAL) for (int CNT = 0; CNT < (int)(GOAL); CNT++)
#define rep2(CNT, START, GOAL) for (int CNT = (int)(START); CNT < (int)(GOAL); CNT++)
#define rep3(CNT, START, GOAL) for (int CNT = (int)(START); CNT > (int)(GOAL); CNT--)
#define all(CONT) begin(CONT), end(CONT)
#define itrep(ITR, CONT) for (auto ITR = begin(CONT); ITR != end(CONT); ITR++)
#define itrep1(ITR, CONT) for (auto ITR = next(begin(CONT)); ITR != end(CONT); ITR++)
template <typename T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template <typename T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
void prec(const int &DIG) { cerr << fixed << setprecision(DIG); cout << fixed << setprecision(DIG); }
template <typename T> void CERR(const T &ELEM) { cerr << ELEM; }
template <typename T, typename ...Ts> void CERR(const T &FIRST, const Ts &...REST) { CERR(FIRST); cerr << ", "; CERR(REST...); }
template <typename T1, typename T2> void CERR(const pair<T1, T2> &PAIR) { cerr << "("; CERR(PAIR.first); cerr << ", "; CERR(PAIR.second); cerr << ")"; }
template <typename T> void CERR(const vector<T> &VEC) { cerr << "{ "; itrep(ITR, VEC) { CERR(*ITR); cerr << ", "; } cerr << "}"; }
template <typename T> void CERR1(const vector<T> &VEC) { cerr << "{ "; itrep1(ITR, VEC) { CERR(*ITR); cerr << ", "; } cerr << "}"; }
template <typename T> void CERR(const set<T> &SET) { cerr << "{ "; itrep(ITR, SET) { CERR(*ITR); cerr << ", "; } cerr << "}"; }
template <typename T> void CERR(const multiset<T> &MULTISET) { cerr << "{ "; itrep(ITR, MULTISET) { CERR(*ITR); cerr << ", "; } cerr << "}"; }
template <typename T1, typename T2> void CERR(const map<T1, T2> &MAP) { cerr << "{ "; itrep(ITR, MAP) { CERR(*ITR); cerr << ", "; } cerr << "}"; }
#define db(OBJ) cerr << #OBJ << ": "; CERR(OBJ); cerr << ", "
#define dbl(OBJ) cerr << #OBJ << ": "; CERR(OBJ); cerr << "\n"
#define db1(OBJ) cerr << #OBJ << ": "; CERR1(OBJ); cerr << "\n"
#define dbs(...) cerr << "(" << #__VA_ARGS__ << "): ("; CERR(__VA_ARGS__); cerr << ")\n"
#define dbvv(VV) cerr << #VV << ": {\n"; rep(CNT, VV.size()) { cerr << #VV << "[" << CNT << "]: "; CERR(VV[CNT]); cerr << ",\n"; } cerr << "}\n"
#define db01(VV) cerr << #VV << ": {\n"; rep(CNT, VV.size()) { cerr << #VV << "[" << CNT << "]: "; CERR1(VV[CNT]); cerr << ",\n"; } cerr << "}\n"
#define db10(VV) cerr << #VV << ": {\n"; rep2(CNT, 1, VV.size()) { cerr << #VV << "[" << CNT << "]: "; CERR(VV[CNT]); cerr << ",\n"; } cerr << "}\n"
#define db11(VV) cerr << #VV << ": {\n"; rep2(CNT, 1, VV.size()) { cerr << #VV << "[" << CNT << "]: "; CERR1(VV[CNT]); cerr << ",\n"; } cerr << "}\n"
#define YN(FLG) cout << (FLG ? "YES" : "NO") << "\n"
#define Yn(FLG) cout << (FLG ? "Yes" : "No") << "\n"
#define yn(FLG) cout << (FLG ? "yes" : "no") << "\n"
// const ll INF = 1'000'000'000'000'000'007;
const int INF = 1'000'000'007;
const ll MOD = 1'000'000'007; // 998'244'353;

ll rem(ll x) { x %= MOD; if(x < 0) x += MOD; return x; }
ll madd(ll x, ll y) { return (rem(x) + rem(y)) % MOD; }
ll msub(ll x, ll y) { return madd(x, -y); }
ll mmul(ll x, ll y) { return rem(x) * rem(y) % MOD; }
ll mpow(ll x, ll n) { assert(n >= 0); ll res = 1; while (n > 0) { if (n & 1) res = mmul(res, x); x = mmul(x, x); n >>= 1; } return res; }
ll inv(ll x) { assert(x % MOD != 0); return mpow(x, MOD - 2); }
ll mdiv(ll x, ll y) { return mmul(x, inv(y)); }
void mad(ll &x, const ll y) { x = madd(x, y); }
void msb(ll &x, const ll y) { x = msub(x, y); }
void mml(ll &x, const ll y) { x = mmul(x, y); }
void mdv(ll &x, const ll y) { x = mdiv(x, y); }

int main() {
	int N; cin >> N;
	vl A(N); rep(i, N) cin >> A[i];
	ll sum = 0;
	rep(i, N) mad(sum, A[i]);
	ll qsum = 0;
	rep(i, N) mad(qsum, mmul(A[i], A[i]));
	ll ans = mdiv(msub(mmul(sum, sum), qsum), 2);
	cout << ans << endl;
}
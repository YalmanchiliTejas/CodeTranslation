#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#include <random>
using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mii;
typedef pair<int, ii> edge;


#define sc(x)  scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define mem(arr,val) memset(arr,val,sizeof arr)
#define sz(v) (int)v.size()
#define rsz(v) v.resize
#define clr(v) v.clear()
#define rev(v) reverse(all(v))
#define lop(i,end) for(int i=0; i<end; i++)
#define rlop(i,start) for(int i=start-1; i>=0; i--)
#define loop(i,start,end) for(int i=start; i<end; i++)
#define rloop(i,start,end) for(int i=start-1; i>=end; i--)
#define PB push_back
#define pb pop_back
#define mP make_pair
#define f first
#define s second

const ll OO = (ll)(4e18) + 9;
const int MOD = (int)(1e9) + 7;
const int oo = 2147483647;
const double EPS = 1e-8;
const double PI = acos(-1.0);

//enum dir { D, R, U, L , dr, ur, dl, ul };
int dx[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

string abc = "abcdefghijklmnopqrstuvwxyz";
string vowels = "aeiouy"; //and sometimes "aeiouy"

template<typename X, typename Y> bool ckmin(X& a, Y b) { return a > b ? a = b, true : false; }
template<typename X, typename Y> bool ckmax(X& a, Y b) { return a < b ? a = b, true : false; }
bool cklex(string &a, string b) {
	if (b == "") return false;
	if (a == "") return a = b, true;
	if (sz(a) < sz(b)) return false;
	if (sz(b) < sz(a)) return a = b, true;
	if (a < b) return false;
	return a = b, true;
}

int dcmp(ld d1, ld d2) { return fabs(d1 - d2) <= EPS ? 0 : d1 > d2 ? 1 : -1; } //Compare Double Numbers
ll gcd(ll x, ll y) { return !y ? x : gcd(y, x%y); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
int conv_2_1(int r, int c, int nCol) { return (nCol*r) + c + 1; } //convert index from 2D array to 1D array. (Zero-indexed)
ii conv_1_2(int n, int nCol) { return{ n / nCol, n % nCol }; } //convert index from 1D array to 2D array (row, col). (Zero-indexed)
template<typename T> void inter(T X) { cout << X << endl; fflush(stdout); }


void _solveE_() {
	ull n, x, m;
	cin >> n >> x >> m;
	map<ull, int> mp;
	ull ans = 0;
	int i = 0;
	vector<ull> v;
	while (i < n and x) {
		if (mp[x]++) {
			int idx = 0;
			lop(j, sz(v)) if (v[j] == x) {
				idx = j;
				break;
			}
			ull szz = sz(v) - idx;
			ull div = (n - (ull)i) / szz;
			ull rem = (n - (ull)i) % szz;
			loop(j, idx, sz(v)) {
				if (j - idx < rem) ans += v[j];
				ans += div * v[j];
			}
			break;
		}
		v.push_back(x);
		ans += x;
		x = ((x%m)*(x%m)) % m;
		i++;
	}
	cout << ans << endl;
}

void _solveD_() {

}

void _solveC_() {

}

void _solveB_() {

}

void _solveA_() {

}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t = 1, tt = 0;
	//cin >> t;
	while (tt++ != t) {
		_solveE_();
	}


	return 0;
}

#include <iostream>
#include <algorithm>
#include <utility>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> pl;
typedef double db;

#define in(x) cin >> x
#define ini(x) int x; cin >> x
#define inl(x) ll x; cin >> x
#define ins(x) string s; cin >> x

#define out(x) cout << x
#define outb(x) cout << x << ' '
#define outn(x) cout << x << '\n'

#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define sz size()
#define len length()
#define all(x) x.begin(), x.end()
#define alln(a, n) a, a+n 

#define forn(i, s, e) for (int i = s; i < e; i++)
#define forr(i, s, e) for (int i = s; i >= e; i--)
#define ford(i, s, e, d) for (int i = s; i < e; i += d)
#define fors(i, n) for (int i = 1; i*i <= n; i++)

string b[109];
int f[109][109];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ini(h); ini(w);
	string bh, bw;
	forn(i, 0, h) bh += '.';
	forn(i, 0, w) bw += '.';
	forn(i, 0, h) in(b[i]);
	forn(i, 0, w) {
		string wh;
		forn(j, 0, h) wh += b[j][i];
		if (wh == bh) forn(j, 0, h) f[j][i] = 1;
	}
	forn(i, 0, h) {
		if (b[i] == bw) continue;
		forn(j, 0, w) if (!f[i][j]) out(b[i][j]);
		outn("");
	}
	
		
	return 0;
}

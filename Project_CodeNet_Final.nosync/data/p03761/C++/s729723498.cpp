#include "bits/stdc++.h"
using namespace std;
#define repi(i,a,b) for(int i=(a), i##_len=(b); i<i##_len; ++i)
#define rep(i,n) repi(i,0,n)
#define repi_(i,a,b) for(int i=(a), i##_len=(b); i<=i##_len; ++i)
#define rep_(i,n) repi_(i,0,n)
#define all(x) (x).begin(),(x).end()
#define vsort(v) sort((v).begin(), (v).end())
#define gsort(v) tsort(v); reverse((v).begin(), (v).end())
#define vrev(v) reverse((v).begin(), (v).end())
#define siz(v) ((int)(v).size())
#define ers(v, n) (v).erase((v).begin() + n)
#define cnt(v, n) count(all(v), n)
#define vmin(v) *min_element(v.begin(), v.end())
#define vmax(v) *max_element(v.begin(), v.end())
#define el "\n"
#define co(x) cout<<(x)<<el
#define coc(c, a, b) if(c)co((a));else co((b))
#define cosp(x) cout<<(x)<<' '
#define YES(c) coc(c,"YES", "NO")
#define Yes(c) coc(c,"Yes", "No")
#define yes(c) coc(c,"yes", "no")
#define inf INT_MAX
#ifdef tqktmp_2
#define gc() getchar(); getchar()
#else
#define gc() 1
#endif
typedef long long lint;

lint dx[8] = { 0,1,1,1,0,-1,-1,-1 },
dy[8] = { 1,1,0,-1,-1,-1,0,1 };

template<class T>inline bool maxi(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>inline bool mini(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }


int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	lint n; cin >> n;
	string s[50];
	lint f[26] = { }, ftmp[26] = {0};
	rep(i, 26)f[i] = INT_MAX;

	rep(i, n) {
		cin >> s[i];
		rep(j, 26) {
			ftmp[j] = 0;
		}
		rep_(j, s[i].length()) {
			ftmp[s[i][j] - 'a']++;
		}
		rep(j, 26) {
			mini(f[j], ftmp[j]);
		}
	}
	
	rep(i, 26) {
		rep(j, f[i]) {
			cout << (char)('a' + i);
		}
	}
	cout << el;
	
	gc();
}
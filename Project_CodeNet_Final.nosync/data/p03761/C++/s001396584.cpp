#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<vector<pair<int, int> > > vvp;
typedef vector<pair<int, int> > vp;
typedef vector<vector<int> > vvi;
typedef vector<int> vi;
typedef vector<vector<ll> > vvl;
typedef vector<ll> vl;
typedef vector<vector<bool> > vvb;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef pair<string, int> psi;
typedef pair<int, int> pii;
#define rep(i,s,n) for(int i = (s); i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define yn(f) (f?"yes":"no")
#define YN(f) (f?"YES":"NO")
#define Yn(f) (f?"Yes":"No")
#define puts(s) cout<<(s)<<endl
#define inf (1000000007)
#define nil -1

int main() {
	int n; cin >> n;
	vs S(n);
	vvi alf(n,vi(26));
	rep(i, 0, n) {
		cin >> S[i];
	}
	string ans = "";
	rep(i, 0, n) {
		rep(j, 0, S[i].size()) {
			
			alf[i][S[i][j] - 'a']++;
		}
	}

	rep(i, 0, 26) {
		int min_=1000000000;
		rep(j, 0, n) {
			min_ = min(min_,alf[j][i]);
		}
		rep(j, 0, min_) {
			ans += ('a'+i);
		}
	}
	sort(all(ans));
	puts(ans);
}

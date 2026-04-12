#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <memory.h>
#include <cassert>

using namespace std;


#define all(c) ((c).begin()), ((c).end())
#define debug(c) cerr << "> " << #c << " = " << (c) << endl;
#define iter(c) __typeof((c).begin())
#define present(c, e) ((c).find((e)) != (c).end())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define tr(i, c) for (iter(c) i = (c).begin(); i != (c).end(); i++)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)

#define mp make_pair
#define fst first
#define snd second
#define pb push_back


const double EPS = 1e-10;


typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef complex<double> P;


bool comp (const pair<string, int> &a, const pair<string, int> &b) {
	if (a.snd > b.snd) return true;
	if (a.snd < b.snd) return false;
	return a.fst < b.fst;
}

int main() {
	for(int N, M, K, L; scanf("%d %d %d %d", &N, &M, &K, &L), (N | M | K | L) != 0; ) {
		vector<pair<string, int> > ns;
		map<string, int> nx;
		rep(i, N) {
			char name[20];
			int x;
			scanf("%s %d", name, &x);
			ns.pb(mp(name, x));
			nx[string(name)] = x;
		}
		set<string> favs;
		vector<pair<string, int> > fx;
		vector<pair<string, int> > nfx;
		rep(i, M) {
			char name[20];
			scanf("%s", name);
			favs.insert(name);
			fx.pb(mp(name, nx[string(name)]));
		}
		
		rep(i, N) if (!present(favs, ns[i].fst)) {
			nfx.pb(ns[i]);
		}
		
		sort(all(fx), comp);
		sort(all(nfx), comp);
		
//		tr(it, ns) cout << it->fst << " " << it->snd << endl;
		
		
		int lb = 0, ub = min(M, K) + 1;
		int mi;
		ll l = L;
		rep(loop, 20) {
			mi = (lb + ub) / 2;
			int r = K - mi;
			if (r >= nfx.size()) {
				lb = mi;
				l = L;
				continue;
			}
			l = L;
			rep(i, mi) {
				if (fx[i].snd > nfx[r].snd) continue;
				if (fx[i].snd < nfx[r].snd) {
					l -= nfx[r].snd - fx[i].snd;
				}
				if (fx[i].fst > nfx[r].fst) l--;
			}
			
			if (l < 0) {
				ub = mi;
			}
			else {
				lb = mi;
			}
		}
		if (l < 0) mi = 0;
		cout << mi << endl;
		
	}
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) FOR(i, 0, (n))
#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define LAR(a, b) ((a)=max((a),(b)))
#define SML(a, b) ((a)=min((a),(b)))
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;
template<typename T>
using pque = priority_queue<T, vector<T>, greater<T>>;
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define ALL(a) (a).begin(), (a).end()
#ifdef LOCAL_DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

using ul = unsigned long long;
constexpr int N = 512;
int s[2][N];
ul u[2][N], a[N][N] = {};

void prt(int n){
	REP(i, n){
		REP(j, n){
			printf("%llu ", a[i][j]);
		}
		printf("\n");
	}
}

enum Quantifier {
	ALL, EXISTS,
};
pair<Quantifier, bool> get_constraints(bool p, bool q){
	if(!p && !q) return {EXISTS, 0};
	if( p && !q) return {ALL, 0};
	if( p &&  q) return {EXISTS, 1};
	if(!p &&  q) return {ALL, 1};
	exit(1);  // unreachable
}

bool b[N][N];
bool c[N], d[N];
vector<int> f, g;
void rev(){
	REP(i, N) REP(j, i) swap(b[i][j], b[j][i]);
	swap(c, d);
	swap(f, g);
}
#define REV for(int h = 0; h < 2; rev(), h++)

int main(){
	int n; scanf("%d", &n);
	REP(h, 2) REP(i, n) scanf("%d", s[h]+i);
	REP(h, 2) REP(i, n) scanf("%llu", u[h]+i);
	REP(k, 64){
		ul m = 1uLL << k;

		REV {
			f.clear();
			REP(i, n){
				auto [q, v] = get_constraints(s[h][i], u[h][i] & m);
				if(q == ALL) REP(j, n) b[i][j] = v;
				else{
					c[i] = v;
					f.EB(i);
				}
			}
		}

		REV {
			if((int)f.size() != 1) continue;
			int ii = f[0];
			for(int j : g){
				bool ex = false;
				REP(i, n) if(i != ii) ex |= b[i][j] == d[j];
				if(ex) b[ii][j] = c[ii];
				else b[ii][j] = d[j];
			}
			f.clear();
		}

		REP(i, (int)f.size()){
			REP(j, (int)g.size()){
				b[f[i]][g[j]] = (i+j)%2;
			}
		}

		// REP(i, n){
		// 	REP(j, n) DEBUG("%d ", b[i][j]);
		// 	DEBUG("\n");
		// }
		// DEBUG("\n");

		REP(i, n) REP(j, n) if(b[i][j]) a[i][j] |= m;
	}

	REP(h, 2){
		REP(i, n){
			ul p[2] = {~0ull, 0};
			REP(j, n){
				p[0] &= a[i][j];
				p[1] |= a[i][j];
			}
			if(p[s[h][i]] != u[h][i]) {
#ifdef LOCAL_DEBUG
				DEBUG("h=%d, i=%d, p=[%llu, %llu], c=[%d, %llu]\n", h, i, p[0], p[1], s[h][i], u[h][i]);
				prt(n);
#endif
				printf("-1\n");
				return 0;
			}
		}
		REP(i, N) REP(j, i) swap(a[i][j], a[j][i]);
	}

	prt(n);
}



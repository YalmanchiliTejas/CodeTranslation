#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <fstream>

using namespace std;
#define TOSTRING(x) #x
#define SZ(x) (int)(x).size()
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REPR(i,n) for(int i=(n)-1;i>=0;i--)
#define ALL(s) (s).begin(), (s).end()
#define so(V) sort(ALL(V))
#define rev(V) reverse(ALL(V))
#define uni(v) v.erase( unique(ALL(v)) , v.end());
#define PAU system("pause")

typedef long long unsigned int llu;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vb> vvb;
const int EPS = 1e-9;
const int MOD = 1e9 + 7;
const int INF = (1 << 30);
const double PI = acos(-1);

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vvb B(N, vb(N, false));
	REP(i, M) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		B[a][b] = true;
		B[b][a] = true;
	}
	vi V(N);
	int ans = 0;
	REP(i, N)V[i] = i;
	do {
		if (V[0] != 0)break;
		bool b = true;
		REP(i, N - 1) {
			if (not B[V[i]][V[i + 1]])b = false;
		}
		if (b)ans++;
	} while (next_permutation(ALL(V)));
	cout << ans << endl;
	PAU;
	return 0;
}

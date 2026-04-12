#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define inf 1000000005
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a))
#define mod 1000000007
#define sz(a) ((ll)(a).size())

template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s);}
#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define Repd(i,n) for(int i = (n)-1; i >= 0; --i)
#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)

typedef unsigned long long ull;
typedef long long ll;
typedef double ld;
#define eps 1e-12
typedef pair<int, int> II;
typedef pair<ll, ll> LL;
template<class T> T gcd(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
#define PI (2 * acos((ld)0))
#define linf (1ll << 60)
#define y1 y32432
#define y0 y435346

#define maxn 400005

int n, deg[maxn], que[maxn], size, flag[maxn];
vector<int> V[maxn];

int main()
{
//	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	For(i, 1, n - 1){
		int u, v;
		cin >> u >> v;
		V[u].pb(v);
		V[v].pb(u);
		deg[u]++;
		deg[v]++;
	}

	size = 0;
	For(i, 1, n) if(deg[i] == 1){
		que[size++] = i;
	}

	Rep(i, size){
		int u = que[i];
		if(flag[u]) continue;
		flag[u] = 1;
		if(deg[u] == 0){
			cout << "First" << endl;
			return 0;
		}
		Rep(j, sz(V[u])){
			int v = V[u][j];
			if(flag[v]) continue;
			flag[v] = 1;
			Rep(k, sz(V[v])){
				int t = V[v][k];
				deg[t]--;
				if(!flag[t] && deg[t] <= 1){
					que[size++] = t;
				}
			}
		}
	}

	cout << "Second" << endl;

  return 0;
}

#include <bits/stdc++.h>
#define ADD(a, b) a = (a + ll(b)) % mod
#define MUL(a, b) a = (a * ll(b)) % mod
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define rer(i, a, b) for(int i = int(a) - 1; i >= int(b); i--)
#define all(a) (a).begin(), (a).end()
#define sz(v) (int)(v).size()
#define pb push_back
#define sec second
#define fst first
#define debug(fmt, ...) Debug(__LINE__, ":", fmt, ##__VA_ARGS__)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<int, pi> ppi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> mat;
typedef complex<double> comp;
void Debug() {cout << '\n'; }
template<class FIRST, class... REST>void Debug(FIRST arg, REST... rest){
	cout<<arg<<" ";Debug(rest...);}
template<class T>ostream& operator<<(ostream& out,const vector<T>& v) {
	out<<"[";if(!v.empty()){rep(i,0,sz(v)-1)out<<v[i]<<", ";out<<v.back();}out<<"]";return out;}
template<class S, class T>ostream& operator<<(ostream& out,const pair<S, T>& v){
	out<<"("<<v.first<<", "<<v.second<<")";return out;}
const int MAX_N = 200010;
const int MAX_V = 100010;
const double eps = 1e-6;
const ll mod = 1000000007;
const int inf = 1 << 29;
const ll linf = 1LL << 60;
const double PI = 3.14159265358979323846;
///////////////////////////////////////////////////////////////////////////////////////////////////

int dx[2] = {1, 0};
int dy[2] = {0, 1};

int H, W;
ll A[210][210];
ll dp[210][210][410];

void solve() {
	cin >> H >> W;
	rep(i, 0, H) {
		rep(j, 0, W) {
			cin >> A[i][j];
		}
	}
	if(H <= 2) {
		ll sum = 0;
		rep(i, 0, H) {
			rep(j, 0, W) {
				sum += A[i][j];
			}
		}
		cout << sum << "\n"; return;
	}
	dp[0][0][0] = A[0][0];
	rep(i, 0, H) {
		rep(j, 0, W) {
			rep(k, 0, H + W - 3) {
				if(dp[i][j][k]) {
					int x1 = i, y1 = k - x1;
					int x2 = j, y2 = k - x2;
					rep(m, 0, 2) {
						rep(n, 0, 2) {
							int nx1 = x1 + dx[m], ny1 = y1 + dy[m];
							int nx2 = x2 + dx[n], ny2 = y2 + dy[n];
							// debug(x1, y1, x2, y2, nx1, ny1, nx2, ny2);
							if(nx1 < H && nx2 < H && ny1 < W && ny2 < W) {
								if(nx1 != nx2 || ny1 != ny2) {
									MAX(dp[nx1][nx2][k + 1], dp[i][j][k] + A[nx1][ny1] + A[nx2][ny2]);
								}
							}
						}
					}
				}
			}
		}
	}
	cout << dp[H - 2][H - 1][H + W - 3] + A[H - 1][W - 1] << "\n";
}

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
    cin.tie(0);
#endif
    cout << fixed;
	cout.precision(20);
	srand((unsigned int)time(NULL));
#ifdef LOCAL
	//freopen("in.txt", "wt", stdout); //for tester
    freopen("in.txt", "rt", stdin);
#endif	
	solve();
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}


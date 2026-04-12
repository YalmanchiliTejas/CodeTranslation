#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;i<(n);i++)
#define rrep(i,n) for(int (i)=1;i<=(n);i++)
#define REP(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define MOD 1000000007
#define INF 1e18
#define int long long
#define endl "\n"
#define yorn(f) puts((f)?"Yes":"No")
#define YORN(f) puts((f)?"YES":"NO")
typedef long long ll;
typedef pair<int, int> P;
int gcd(int a,int b){return b?gcd(b,a%b):a;};
int lcm(int a,int b){return a/gcd(a,b)*b;};
int mod(int a,int b){return (a+b-1)/b;};
template<typename A, size_t N, typename T>
void Fill(A(&array)[N],const T &val){std::fill((T*)array,(T*)(array+N),val);}
template<class T>inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;};
template<class T>inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;};



signed main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
	
	int n;
	cin >> n;
	int a[n];
	rep(i, n) {
		cin >> a[i];
		//a[i] %= MOD;
	}
	int sum[n+10] = {}, allsum = 0;
	rep(i, n) {
		sum[i+1] = (sum[i] + a[i]) % MOD;
		allsum += a[i];
		sum[i+1] %= MOD;
		allsum %= MOD;
	}
	int ans = 0;
	rep(i, n-1) {
		int now = (allsum + 2 * MOD - sum[i] - a[i]) % MOD;
		now = now * a[i] % MOD;
		ans += now, ans %= MOD;
		//cout << allsum - sum[i] - a[i] << endl;
	}
	cout << ans << endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define __ <<" "<<
#define ___ <<" "
#define bash push_back
#define ALL(x) x.begin(),x.end()
// #define int long long
struct IoSetup {
    IoSetup() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
        cerr << fixed << setprecision(10);
    }
}IoSetup;

using Int = __int128_t;
using ll = long long;
using pii = pair<int, int>;
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr int SMOD = 1000000007;
constexpr int NMOD = 998244353;
constexpr int dx[]={1,0,-1,0,1,1,-1,-1};
constexpr int dy[]={0,-1,0,1,-1,1,-1,1};

inline bool inside(int x,int y,int w,int h){return (x>=0 && y>=0 && x<w && y<h);}
template<class T>bool chmax(T &a, const T&b){if(a<b)return(a=b,1);return 0;}
template<class T>bool chmin(T &a, const T&b){if(b<a)return(a=b,1);return 0;}


signed main() {
    
	int64_t n, x, m;
	cin >> n >> x >> m;

	map<int, int> s;

	vector<int64_t> sum;

	int64_t a = x;
	sum.bash(x);

	for(int i = 0; i < n - 1; i++) {
		int64_t t = a * a % m;

		if(s.find(t) != s.end()) {
			int64_t ans = sum[s[t]];
			int l = i - s[t];
			int64_t lo = sum[i] - sum[s[t]];
			n -= s[t] + 1;

			ans += lo * (n / l);
			n %= l;
			a = t;


			for(int k = 0; k < n; k++) {
				ans += a;
				a = a * a % m;
			}
			cout << ans << endl;
			return 0;
		}
		else {
			s[t] = i;
			a = a * a % m;
			sum.bash(sum.back() + a);
		}
	}

	cout << sum.back() << endl;

    return 0;
}

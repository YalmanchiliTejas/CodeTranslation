#include<iostream>
#include<string>
#include<cstdio>
#include <cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
const ll INF = 1e+14;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define pb push_back
#define int long long

void Yes(){
	cout<<"Yes"<<endl;
	exit(0);
}
 
void No(){
	cout<<"No"<<endl;
	exit(0);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    int N; cin >> N;
    ll s[100100];
    rep(i, N) cin >> s[i];
    ll dp[100100];
    ll ans = s[N - 1];
    rep1(C, N - 2) {
        int n_max = (N - 1) / C - 1;
        if(n_max < 1) break;
        if((N - 1) % C == 0) {
            dp[0] = s[N - 1];
            rep1(n, n_max) {
                if(n * C >= N - 1 - n * C) break;
                if(n * C < N - 1 && N - 1 - n * C > 0) {
                    dp[n] = dp[n - 1] + s[n * C] + s[N - 1 - n * C];
                    ans = max(ans, dp[n]);
                }
            }
        } else {
            dp[0] = s[N - 1];
            rep1(n, n_max) {
                if(n * C < N - 1 && N - 1 - n * C > 0) {
                    dp[n] = dp[n - 1] + s[n * C] + s[N - 1 - n * C];
                    ans = max(ans, dp[n]);
                }
            }
        }
    }
    cout << ans << endl;
	return 0;
}
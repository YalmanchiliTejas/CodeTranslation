#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
ll const mod = 998244353;

#define p_ary(ary,a,b) do { cout << "["; for (int count = (a);count < (b);++count) cout << ary[count] << ((b)-1 == count ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

template<typename T1,typename T2>ostream& operator<<(ostream& os,const pair<T1,T2>& a) {os << "(" << a.first << ", " << a.second << ")";return os;}

const char newl = '\n';

int main() {
    int n,s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0;i < n;++i) cin >> a[i];
    vector<vector<ll>> dp(n+1,vector<ll>(s+1,0));
    for (int i = 0;i < n;++i) dp[i][0] = 1;
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < s+1;++j) {
            (dp[i+1][j] += dp[i][j]) %= mod;
            if (j+a[i] <= s) (dp[i+1][j+a[i]] += dp[i][j]) %= mod;
        }
    }
    ll ans = 0;
    for (int i = 0;i < n+1;++i) (ans += dp[i][s]) %= mod;
    cout << ans << endl;
}
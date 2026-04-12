#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b) do { cout << "["; for (int count = (a);count < (b);++count) cout << ary[count] << ((b)-1 == count ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

template<typename T1,typename T2>ostream& operator<<(ostream& os,const pair<T1,T2>& a) {os << "(" << a.first << ", " << a.second << ")";return os;}

const char newl = '\n';

void chmax(ll& a,ll b) {
    a = max(a,b);
}

int main() {
    ll const INF = 1e18;
    int n;
    cin >> n;
    vector<int> a(n);
    vector<array<ll,4>> dp(n+2,{-INF,-INF,-INF,-INF});
    dp[0][0] = 0;
    for (int i = 0;i < n;++i) cin >> a[i];
    for (int i = 0;i < n;++i) {
        if (i%2) {
            chmax(dp[i+1][0],dp[i][1]);
            chmax(dp[i+1][0],dp[i][0]);
            chmax(dp[i+1][2],dp[i][3]);
            chmax(dp[i+1][2],dp[i][2]);
            chmax(dp[i+1][1],dp[i][2]+a[i]);
        } else {
            chmax(dp[i+1][1],dp[i][0]+a[i]);
            chmax(dp[i+1][2],dp[i][0]);
            chmax(dp[i+1][2],dp[i][1]);
            chmax(dp[i+1][3],dp[i][2]+a[i]);
        }
    }
    // for (int i = 0;i < n+1;++i) p_ary(dp[i],0,4);
    cout << max(dp[n][(n&1)*2],dp[n][(n&1)*2+1]) << endl;
}
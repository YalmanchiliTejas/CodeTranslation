#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,LL> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
const LL mod=998244353;
const LL LINF=1LL<<62;
const int INF=1<<30;
int dx[]={1,0,-1,0,1,-1,1,-1};
int dy[]={0,1,0,-1,1,-1,-1,1};




int main(){
    int n,s;cin >> n >> s;
    vector<LL> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    LL ans = 0;
    vector<LL> dp(5000,0);
    for (LL i = 0; i < n; i++) {
        for (int j = s; j >= 0; j--) {
            if(j + a[i] <= s) dp[j + a[i]] = (dp[j + a[i]] + dp[j])%mod;
        }
        dp[a[i]] = (dp[a[i]] + i + 1)%mod;
        ans = (ans + dp[s])%mod;
    }
    cout << ans << endl;
    return 0;
}

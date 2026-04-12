#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define for1(i, n) for (int i = 1; i <= int(n); ++i)
#define ms(a, x) memset(a, x, sizeof(a))
#define F first
#define S second
#define all(x) (x).begin(),(x).end()

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
mt19937 gen(random_device{}());
template<typename... Args> void write(Args... args) { ((cout << args << " "), ...); cout<<endl;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i) cin>>a[i];
    vector<vector<ll>> dp(n+1,vector<ll>(3,-1e18));
    dp[1]={0,0,0};
    for(int i=2;i<=n;++i){
        if(i&1){
            dp[i][0]=max({dp[i-2][0],dp[i-2][1],dp[i-2][2]})+a[i];
            dp[i][1]=dp[i-1][0];
            dp[i][2]=dp[i-1][1];
        }else{
            dp[i][0]=max({dp[i-1][1]+a[i],dp[i-1][2]+a[i]});
            dp[i][1]=dp[i-1][2]+a[i-1];
        }
    }
    cout<<*max_element(all(dp[n]));
    return 0;
}


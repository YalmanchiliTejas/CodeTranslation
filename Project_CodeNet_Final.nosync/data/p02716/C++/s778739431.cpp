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
    vector<int> a(n);
    for(auto& it:a) cin>>it;
    int buf=(n&1?3:2);
    vector<vector<ll>> dp(n+1,vector<ll>(buf,-1e18));
    dp[0][0]=0;
    forn(i,n){
        forn(j,buf){
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]+((i+j)%2==0?a[i]:0));
            if(j+1<buf) dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]);
        }
    }
    cout<<dp[n][buf-1];
    return 0;
}


// hackerearth incom
        #include <bits/stdc++.h>

        using namespace std;

        typedef long long ll;
        const ll N = 5e5+5;
        const ll MOD = 1000000007;
        #define all(x) x.begin(),x.end()
        #define pii pair<ll,ll>
        #define pis pair<ll,string>
        #define F first
        #define S second
        #define LCM(a,b) ((a*b)/__gcd(a,b))
        #define inf 1e15
        #define test ll cse;cin>>cse;for(ll _i=1;_i<=cse;_i++)
        #define PI 3.14159265
        #define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
        const double EPS = 1E-9;
        typedef vector<vector<double>> matrix;
        typedef vector<int> vi;


int main(){

    fast;
    int n;
    ll ar[N];
    ll dp[N];
    memset(ar, 0, sizeof ar);
    memset(dp, 0, sizeof dp);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> ar[i];
    for(int i = 1; i <= n; i++) dp[i] = (dp[i-1] + ar[i]) % MOD;

    ll ans = 0;

    for(int i = 1; i <= n; i++) {
        ll A = (dp[n] - dp[i] + MOD) % MOD;
        ll B = (ar[i]) % MOD;

        ans = (ans % MOD + (A*B) % MOD) % MOD;
    }

    cout << ans << "\n";
    return 0;
}

#include <bits/stdc++.h>
#define maxn 100001
#define maxa 1000005
#define MOD 1000000007
#define INF 1000000000000000000

using namespace std;

#define ll long long
#define pii pair<ll, ll>
#define piii pair<pii, ll>
#define ft first
#define sd second
#define rep(i, a, n) for(ll i = a; i < n; i++)
#define repr(i, a, n) for(ll i = n-1; i >= a; i--)
#define meme(a, b) memset(a, b, sizeof(a))

void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
ll ceil(ll a, ll b){if((a%b) != 0) return a/b+1; return a/b;}
void flaged(bool flag){
    if(flag) cout << "YES\n";
    else cout << "NO\n";
}
ll power(ll a, ll b = MOD-2){
    if(b == 0) return 1;
    ll r = power(a, b/2);
    r = (r*r)%MOD;
    if(b%2 == 1) r = (r*a)%MOD;
    return r;
}

void solve(){
    string s; ll k;
    cin >> s >> k;

    ll n = s.length();
    ll dp[n+1][2][10];
    meme(dp, 0);
    dp[0][0][0] = 1;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < 2; j++){
            for(ll kk = 0; kk <= k; kk++){
                ll lim = s[i]-'0';
                if(j == 1) lim = 9; //cout << i << " " << j << " " << kk << " " << lim << endl;
                for(ll d = 0; d <= lim; d++){ //cout << d<< " ";
                    dp[i+1][j || d < lim][kk + (d!=0)] += dp[i][j][kk];
                }
            }
        }
    }
    cout << dp[n][0][k] + dp[n][1][k];
}

int main()
{
    fast();
    ll t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}

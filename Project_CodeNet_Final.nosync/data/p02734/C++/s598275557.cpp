#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
typedef long double ld;
#define INF 0x3f3f3f3f
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (ll i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (ll i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 3005
int n;
int s;
int a[MN];
ll dp[MN][MN]; //after i elements, sum of j. account for extras

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> s;
    FOR(i, 1, n) cin >> a[i];

    ll sm = 0;
    RFOR(i, n, 1){
        if(a[i] < s){
            sm += dp[i+1][s-a[i]]*i;
            sm %= MOD;
        } else if(a[i] == s){
            sm += i*(n-i+1);
            sm %= MOD;
        }
        FOR(j, 1, s-1){
            dp[i][j] += dp[i+1][j];
        }
        FOR(j, a[i]+1, s-1){
            dp[i][j] += dp[i+1][j-a[i]];
            dp[i][j] %= MOD;
        }
        dp[i][a[i]] += (n-i+1);
        dp[i][a[i]] %= MOD;
    }
    /*RFOR(i, n, 1){
        FOR(j, 1, s-1){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }*/

    cout << sm << "\n";

    return 0;
}

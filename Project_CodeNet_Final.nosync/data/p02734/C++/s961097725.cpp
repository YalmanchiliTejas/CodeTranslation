#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb emplace_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define sz(x) (ll)x.size()
#define F first
#define S second
#define FOR(i,a,b) for(ll i=a;i<=b;++i)
#define ROF(i,a,b) for(ll i=a;i>=b;--i)
typedef long long ll;
using namespace std;

const int N = 3001;
const int mod = 998244353;

int n, s;
int a[N];
ll dp[N];

int main(){
    IOS

    cin >> n >> s;
    FOR(i,1,n){
        cin >> a[i];
    }
    ll ans = 0;
    FOR(i,1,n){
        dp[0]++;
        ROF(j,s-a[i],0){
            dp[j + a[i]] = (dp[j + a[i]] + dp[j]) % mod;
        }
        ans = (ans + dp[s]) % mod;
    }
    cout << ans;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define endl '\n'

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const ll mod = 1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// head

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vll a(n);
    ll sum = 0;
    rep(i,0,n) {
        cin >> a[i];
        sum += a[i];
        sum %= mod;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        sum -= a[i];
        if(sum < 0) sum += mod;
        ans = (ans + (a[i] * sum) % mod) % mod;
    }
    cout << ans << endl;
    return 0;
}

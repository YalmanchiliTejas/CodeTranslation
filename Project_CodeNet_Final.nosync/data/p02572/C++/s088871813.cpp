#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << '\n'
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef double db;
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a; }
//head
 
void solve(){
    const ll m = 1e9 + 7;
    int n;
    cin >> n;
    vector<ll> a(n);
    ll s = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        s += a[i];
    }

    ll ans = 0;

    for (int i = 0; i < n; i++){
        ans = (ans%m)+((a[i]%m)*((s-a[i])%m))%m;
        s -= a[i];
    }
    cout << ans << '\n';
}

int main(void){ 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //int t; cin >> t; while (t--)
        solve();
}

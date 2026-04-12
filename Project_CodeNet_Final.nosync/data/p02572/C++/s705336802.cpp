#include<bits/stdc++.h>
#define Rushia_mywife ios::sync_with_stdio(0);cin.tie(0);
#define rep(i,head,n) for(int i=(head);i<n;i++)
#define int long long
#define F first
#define S second
#define pb push_back
#define p2(n) (1<<(n))
#define lg2(n) __lg(n)
using namespace std;
using ll = long long;
using pii = pair<long long,long long>;
using ld = long double;
mt19937 mt_rand(time(0));
const int mod = 1000000007;
const int hnum = 998244353;
const ld PI = acos(-1);
const int N = 2e5+10;

int n;
int a[N];
int s[N];

void solve(){
    cin >> n;
    rep(i,1,n+1)
        cin >> a[i];
    for(int i=n;i>0;i--)
        s[i] = (s[i+1]+a[i])%mod;
    int ans = 0;
    rep(i,1,n)
        ans = (ans+a[i]*s[i+1]%mod)%mod;
    cout << ans << '\n';
}

signed main(){
    Rushia_mywife
    //int t; cin >> t;
    //while(t--)
    solve();
}
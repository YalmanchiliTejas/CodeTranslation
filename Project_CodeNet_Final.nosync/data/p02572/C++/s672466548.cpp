#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
using P = pair <int, int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

ll MOD = 1000000007;
ll INF =1<<30;

int main(){
    int n;
    cin >> n;
    vector<ll>a(n);
    rep(i,n) cin >> a[i];
    ll ans = 0;
    vector<ll> b= a ;
    reverse(b.begin(),b.end());
    vector<ll> w(n);
    w[0] = b[0];
    rep(i,n-1){
        w[i+1] = w[i]+b[i+1];
    }
    rep(i,n){
        if(w[i]>MOD) w[i]%=MOD;
    }
    reverse(w.begin(),w.end());
    rep(i,n-1){
        ans +=a[i]*w[i+1];
        ans%=MOD;
    }
    cout << ans <<endl;
}
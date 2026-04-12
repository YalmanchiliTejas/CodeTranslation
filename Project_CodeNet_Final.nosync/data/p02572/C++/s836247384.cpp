#include <bits/stdc++.h>
#define ll long long
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define per(i, a, b) for (ll i = a; i > b; i--)
#define vi vector<int>
#define vii vector<vi>
#define vl vector<ll>
#define vll vector<vl>
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
#define a(v) (v.begin(), v.end())
#define intlimit 2e9 + 69
#define longlimit 8e18 + 69
#define MOD 1000000007
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a) * (b) / gcd(a, b))
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vl v(n);
    rep(i,0,n){
        cin >> v[i];
    }
    ll suf = 0,sum = 0;
    per(i,n-1,-1){
        sum += suf*v[i];
        sum%=MOD;
        suf+=v[i];
        suf%=MOD;
    }
    cout << sum;
}

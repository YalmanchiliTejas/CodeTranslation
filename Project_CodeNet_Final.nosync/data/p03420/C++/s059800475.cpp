#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=(s);i<(n);i++)
#define repr(i,n) for(int i=n-1;i>=0;i--)
#define REPR(i,s,n) for(int i=(s);i>=(n);i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define pb push_back
#define pf push_front
#define mod 1e9 +7;
typedef long long ll;
typedef vector<ll> vll;
const double phi = (1 + sqrt(5)) / 2;
const double phi_ = (1 - sqrt(5)) / 2;
ll fib(ll n){
    double res = pow(phi, n+1) - pow(phi_, n+1);
    return res / sqrt(5);
}
ll gcd(ll x,ll y)
{
    ll r;
    while((r = x % y) != 0)
    {
        x = y;
        y = r;
    }
    return y;
}
ll lcm(ll x,ll y)
{
    x /= gcd(x,y);
    y /= gcd(x,y);
    return (x*y);
}
string to_bin_string(ll n){
    stringstream ss;
    ss << bitset<8>(n); //任意の桁数<m>
    string s = ss.str();
    return s;
}
int main()
{
    ll n, k, ans = 0;
    cin >> n >> k;
    if(k == 0){
        cout << n*n << endl;
        return 0;
    }
    REP(b,1,n+1){
        ll p = n/b, r = n%b;
        ans += p*max(b-k, (ll)0) + max(r-k+1, (ll)0);
    }
    cout << ans << endl;
    return 0;
} 
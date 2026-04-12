//BISMILLAHIR RAHMANIR RAHIM
//RABBI ZIDNI ILMA
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define endl "\n"
#define inf (1LL<<61)
#define pi acos(-1)
#define mod 1000000007
#define all(x) x.begin(), x.end()
#define fastio ios_base::sync_with_stdio(0);cout<< fixed<< setprecision(10);
#define DEBUG(x) cout<<"["<<#x<<": "<<x<<"]\n"
#define DEBUG2(x, y) cout<<"["<<#x<<": "<<x<<"]"<<"  ["<<#y<<": "<<y<<"]\n"
#define DEBUG3(x, y, z) cout<<"["<<#x<<": "<<x<<"]"<<"  ["<<#y<<": "<<y<<"]"<<"  ["<<#z<<": "<<z<<"]\n"
#define DEBUG4(x, y, z, k) cout<<"["<<#x<<": "<<x<<"]"<<"  ["<<#y<<": "<<y<<"]"<<"  ["<<#z<<": "<<z<<"]"<<"  ["<<#k<<": "<<k<<"]\n"

const ll N = 1e5 + 9;

int main()
{
    fastio
    ll n;
    cin>> n;
    vector<ll> a(n+1), s(n+1);
    for(int i=1; i<=n; i++){
        cin>> a[i];
        s[i] = s[i-1] + a[i];
        s[i] %= mod;
    }
    ll ans = 0;
    for(int i=n; i>=2; i--){
        ans += (a[i] * s[i-1]) % mod;
        ans %= mod;
    }
     cout<< ans;
}


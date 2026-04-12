#include<bits/stdc++.h>
#define ll long long int
#define pragi(a,b) for(ll i = a;i<b;i++)
#define pragj(a,b) for(ll j = a;j<b;j++)
#define pragk(a,b) for(ll k = a;k>=b;k--)
#define all(v) (v.begin(),v.end())
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define MP make_pair
#define MT make_tuple
#define F first
#define S second
#define KAKA ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int mod = 1e9 + 7;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef long double ld;
typedef pair<int, int> pii;
//typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef pair<ll, ll> pll;

void Compute(ll n)
{
    KAKA
    vector<ll> v(n);
    pragi(0,n)
    {
        cin>>v[i];
    }
    vector<ll> suf(n);
    suf[n - 1] = v[n - 1]%mod;
    pragk(n - 2,0)
    {
        suf[k] = (suf[k + 1] + v[k])%mod;
    }
    ll sum = 0;
    pragi(0,n - 1)
    {
        sum = ((sum % mod) + ((v[i] % mod) * (suf[i + 1] % mod))%mod)%mod;
    }
    cout<<sum<<"\n";
}
int main()
{
    KAKA
    ll n;
    cin>>n;
    Compute(n);
}
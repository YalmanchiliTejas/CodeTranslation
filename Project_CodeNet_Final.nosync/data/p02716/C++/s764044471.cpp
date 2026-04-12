#include <iostream>
#include <bits/stdc++.h>
#define mod 998244353

typedef long long ll;

using namespace std;

void Fastio(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll fact[1000006], inv[1000006];

ll fp(ll base, ll exp)
{
    if (exp == 0)
        return 1;
    ll ans = fp(base, exp / 2);
    ans = (ans * ans) % mod;
    if (exp % 2 != 0)
        ans = (ans * (base % mod)) % mod;
    return ans;
}

void calcFacAndInv(ll n)
{
    fact[0] = inv[0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        fact[i] = (i * fact[i - 1]) ;
        inv[i] = fp(fact[i], mod - 2);
    }
}

ll ncr(ll n, ll r)
{
    return ((fact[n] * inv[r]) % mod * inv[n - r]) % mod;
}

ll npr(ll n, ll r)
{
    return (fact[n] * inv[n - r]) % mod;
}

long double  NCR(int n, int m){
    long double res = 1;
    m = min(m, n - m);
    for(int i = 0; i < m; i++){
        res = res * ( n - i) / (i + 1);
 }
    return res;
}
ll tol(string a){
    ll res=0;
    while(a[0]=='0'){
        a.erase(a.begin());
    }
    if(a=="")a="0";
    for(int i=0; i<a.size(); i++){
        res*=10; res+=a[i]-'0';
    }
    return res;
}

int primeFactors(int n)
{
    ll c=0;
    while (n % 2 == 0)
    {
        c++;
        n = n/2;
    }
    for (int i = 3; i*i <= n; i = i + 2)
    {
        while (n % i == 0)
        {
            c++;
            n = n/i;
        }
    }
    if (n > 2)
        c++;
    return c;
}
class data{
    public:
    ll l, r, d, w;
    bool operator <(data& d){
        return w>d.w || (w==d.w && this->d>d.d);
    }
};
/*ll n, arr[200005], dp[200005][2][2];
ll solve(int i, int l, int ch){
    if(i==n)return 0;
    if(dp[i][l][ch]!=-1)return dp[i][l][ch];
    ll res1=-1e18,res2=-1e18;
    if(ch){
        if(!l)res1=solve(i+1,1,1)+arr[i];
        else res1=solve(i+1,0,1);
    }
    else {
        if(!l)res1=solve(i+1,1,0)+arr[i];
        if(l)res2=solve(i+1,0,0);
        else res2=solve(i+2,0,1);
    }
    return dp[i][l][ch]=max(res1,res2);
}*/

int main()
{
    Fastio();
    int n; cin>>n;
    vector<ll> arr, sum(n+10);
    for (int i=1; i<=n; i++) {
        ll x; cin>>x;
        arr.push_back(x);
        if (i%2==1) {
            if (i==1)sum[i]=x;
            else
                sum[i]=sum[i-2]+x;
        }
    }

    /*memset(dp,-1,sizeof(dp));
    cout<<solve(0,0,0)<<'\n';
    */
    ll dp[n+10]={0};
    dp[1]=0;
    for(int i=2; i<=n; i++){
        if(i%2==1)dp[i]=max(dp[i-2]+arr[i-1], dp[i-1]);
        else dp[i]=max(dp[i-2]+arr[i-1], sum[i-1]);
    }
    cout<<dp[n]<<'\n';

    return 0;
}


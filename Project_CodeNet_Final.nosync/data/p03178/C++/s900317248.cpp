#include <iostream>
#include <bits/stdc++.h>
#define mod 1000000007
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
int check(string a, string b){
    for(int i=0; i<a.size(); i++){
        if(a[i]>b[i])return 1;
        if(b[i]>a[i])return -1;
    }
    return 0;
}
class data{
public:
    ll v,d,p;
    data(){}
    data(ll vv, ll dd, ll pp){
        v=vv;  d=dd; p=pp;
    }
};

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
ll d, dp[100005][105][2][2];
string a;
ll solve(int i, int x, int st, int z){
    if(i==a.size())
        return (x==0 && z);
    if(dp[i][x][st][z]!=-1)return dp[i][x][st][z];
    ll res=0, mx=a[i]-'0';
    if(st)mx=9;
    for(int y=0; y<=mx; y++){
        if(y<a[i]-'0')
            res+=solve(i+1,(x+y)%d,1,(z||y>0));
        else res+=solve(i+1,(x+y)%d,st,(z||y>0));
        res%=mod;
    }
    return dp[i][x][st][z]=res;
}

int main()
{
    Fastio();
    cin>>a>>d;
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,0,0,0)<<'\n';

    return 0;
}

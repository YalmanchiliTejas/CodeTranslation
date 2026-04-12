#include <bits/stdc++.h>
#include<string.h>
#include <algorithm> 
#include<math.h>
#include<vector>
#define ll long long
#define M 1000000007
#define Mo 1000000000
#define mm 998244353 
using namespace std;

ll prck(ll n)
{
    ll f=1;
    if(n==1)
        f=0;
    else if(n==2)
        f=1;
    else if(n%2==0)
        f=0;
    else
    {
        ll i;
        for(i=3;(i*i<=n) && (f==1);i+=2)
        {
            if(n%i==0)
                f=0;
        }
    }
    return f;
}

ll nCr(ll n,ll r)
{
    ll i,res = 1;
    if (r>n-r)
        r=n-r;
    for(i=0;i<r;++i)
    {
        res*=(n-i);
        res/=(i+1);
    }
    return res;
}

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

ll btod(string n)
{
    ll lg=n.length();
    ll i,val=0,bs=1;
    for(i=lg-1;i>=0;i--)
    {
        if(n[i]=='1')
        {
            val+=bs;
        }
        bs*=2;
    }
    return val;
}

ll ston(string s)
{
    ll val=0,bs=1;
    ll sl=s.length();
    sl--;
    while(sl>=0)
    {
        val+=((s[sl]-48)*bs);
        bs*=10;
        sl--;
    }
    return val;
}


ll nCrModpDP(ll n, ll r, ll p)
{
    ll i,j,C[r+1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    for (i=1;i<=n;i++)
    {
        for(j=min(i,r);j>0;j--)
        {
            C[j] = (C[j]+C[j-1])%p;
        }
    }
    return C[r];
}
ll nCrModpLucas(ll n,ll r,ll p)
{
   if (r==0)
      return 1;
   ll ni = n%p, ri = r%p;
   return (nCrModpLucas(n/p, r/p, p) *
           nCrModpDP(ni, ri, p)) % p;
}

//(x^y)%p
ll pwr(ll x,ll y,ll p)
{
    ll res=1;
    x = x % p;
    while(y>0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

ll modInverse(ll n,ll p)
{
    return pwr(n, p-2, p);
}

ll nCrModPFermat(ll n, ll r, ll p,ll fac[])
{
   if (r==0)
      return 1;

    return (fac[n]* modInverse(fac[r], p) % p *
            modInverse(fac[n-r], p) % p) % p;
}

/*ll fac[n+1];
        fac[0] = 1;
        ll i;
        for (i=1 ; i<=n; i++)
            fac[i] = fac[i-1]*i%M;*/

/*ll nPr(ll n,ll r,ll m,ll fac[])
{
    ll q=fac[n];
    r=(fac[r])%m;
    return (q*pow(r,m-2))%m;
}*/

// ll power(int x, unsigned int y)
// {
//     int temp;
//     if( y == 0)
//         return 1;
//     temp = power(x, y/2);
//     if (y%2 == 0)
//         return temp*temp;
//     else
//         return x*temp*temp;
// }

//Zeller's Congruence
int calcDate(int date,int month,int year)
{
    if(month==1)
    {
        month=13;
        year--;
    }
    if(month==2)
    {
        month=14;
        year--;
    }
    int q=date,m=month,k=year%100,j=year/100;
    int day = q + (13*(m+1))/5 + k + (k/4) + (j/4) + 5*j;
    day=day%7;
    return day;
}


vector<vector<ll>> matmul(vector<vector<ll>> a,vector<vector<ll>> b)
{
    ll k=a.size();
    vector<vector<ll>> c(k,vector<ll>(k));
    ll i,j,l;
    for(i=0;i<k;i++)
    {
        for(j=0;j<k;j++)
        {
            for(l=0;l<k;l++)
            {
                c[i][j]=(c[i][j]+a[i][l]*b[l][j])%M; //%Mo only if req.
            }
        }
    }
    return c;
}

vector<vector<ll>> matexp(vector<vector<ll>> a,ll p)
{
    if(p==1)return a;
    if(p&1)return matmul(a,matexp(a,p-1));
    vector<vector<ll>> x= matexp(a,p/2);
    return matmul(x,x);
}

//linear recurrence
//find Fn
ll linrec(ll n,ll k,vector<ll> a,vector<ll> b)
{
    if(n==0)return 0;
    if(n<=k)return a[n-1];
    ll i,j;
    vector<ll> F1(k+1);
    for(i=1;i<=k;i++)F1[i]=a[i-1];
    vector<vector<ll>> T(k+1,vector<ll>(k+1));
    for(i=1;i<=k;i++)
    {
        for(j=1;j<=k;j++)
        {
            if(i<k)
            {
                if(j==i+1)
                    T[i][j]=1;
                else T[i][j]=0;
                continue;
            }
            T[i][j]=b[k-j];
        }
    }
    
    T=matexp(T,n-1);
    ll res=0;
    for(i=1;i<=k;i++)
    {
        res+=(T[1][i]*F1[i])%M;
    }
    return res%M;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // ll t;
    // cin>>t;
    // while(t--)
    // {
            
    // }
    string s;
    ll i,n;
    cin>>s;
    n=s.length();
    ll flga=0,flgb=0;
    for(i=0;i<n && (flga+flgb)<2;i++)
    {
        if(s[i]=='A')flga=1;
        else flgb=1;
    }
    if(flga==1 && flgb==1)cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}

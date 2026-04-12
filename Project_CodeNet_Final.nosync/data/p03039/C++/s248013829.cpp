#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define MOD 1000000007

using namespace std;

ll powa(ll x, ll y, ll z)
{
    x%=z;
    ll res = 1;
    while(y>0)
    {
        if(y&1)
            res = (x*res)%z;
        x*=x;
        x%=z;
        y>>=1;
    }
    
    return res;
    
}

ll fact[300000];

ll ncr(ll n, ll r)
{
    if(r>n)
        return 0;
    if(r == 0)
        return 1;
    ll temp = fact[n];
    //cout<<n<<"! = "<<temp<<"\n";
    //cout<<r<<"! = "<<fact[r]<<"\n";
    temp*=powa((fact[r]*fact[n-r])%MOD,MOD-2,MOD);
    temp%=MOD;
    //cout<<n<<" C "<<r<<" = "<<temp<<"\n";
    return temp;
}

ll nc2(ll n)
{
    ll temp = (n)*(n-1);
    temp/=2;
    return temp%MOD;
}

int main()
{
   FAST/**/
   fact[0] = 1;
   for(ll i=1;i<300000;i++)
        fact[i] = (fact[i-1]*i)%MOD;
   
   ll n,m,k;
   cin>>n>>m>>k;
   
   ll ans = 0;
   
   for(ll i=1;i<=n;i++)
   {
       for(ll j=1;j<=m;j++)
       {
           ll temp = ncr(n*m-2,k-2);
           //cout<<"temp = "<<temp<<"\n";
           ll temp1 = (nc2(i)*(j-1)) + nc2(j)*(i-1) + nc2(i)*(m-j) + nc2(m-j+1)*(i-1) + nc2(n-i+1)*(j-1) + nc2(j)*(n-i) + nc2(n-i+1)*(m-j) + nc2(m-j+1)*(n-i);
           //cout<<"at "<<i<<" , "<<j<<" val = "<<temp1<<"\n";
           temp1%=MOD;
           temp1+=nc2(i) + nc2(n-i+1) + nc2(j) + nc2(m-j+1);
           temp1%=MOD;
           //temp1-=(m*j+n*i)%MOD;
           //temp1%=MOD;
           if(temp1<0)
                temp1+=MOD;
           ans+=(temp*temp1)%MOD;
           ans%=MOD;
           
       }
   }
   
   ans*=powa(2,MOD-2,MOD);
   ans%=MOD;
   cout<<ans;
   
   return 0;
}
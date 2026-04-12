#include<bits/stdc++.h>
using namespace std;
#define ll long long int
//map<pair<long long int,long long int>,long long int>mapa;
//pair<ll,ll>v[200005];
ll sum[200005];
//priority_queue<ll>pq;
class Myfirst{
private:
    string *name;       ll *age;
    public:
        ll gcd(ll a ,ll b)
        {   if(b==0) return a;  a%=b;   return gcd(b,a);    }
        ll exte_gcd(ll a,ll b,ll& x,ll& y)
        {
            if(b==0)
            {   x=1; y=0;   return a;   }
            ll x1,y1;             ll d=exte_gcd(b,a%b,x1,y1);
            x=y1;                 y=x1-y1*(a/b);  return d;
        }
        ll powe(ll d,ll s)
        {
            if(s==1) return d;      else if(s==0) return 1;
            else
            {   ll u,v=d;            for(u=1;u<s;u++)    d=d*v;
                return d;
            }
        }
        ll count_divisors(ll b)
        {
                ll i,count=0,n=1;
                for(i=2;i*i<=b;i++)
                {
                    count=0;
                    if(b%i==0)
                    {
                        while(b%i==0)
                        {
                            b=b/i;      count++;
                        }
                        n=n*(count+1);
                    }
                }
                if(b>1) n=2*n;
            return n;
        }
        ll bigmod(ll a,ll b, ll mod)
        {
            if(b==0)
                return 1;
            ll x=bigmod(a,b/2,mod);         x=(x*x)%mod;
            if(b%2) x=(x*a)%mod;
                return x;
        }
        ll phi(ll n)
        {
            double result=n;
            for (ll p=2;p*p<=n;++p){
                if (n%p==0){
                    while(n%p==0)       n/=p;
                    result*=(1.0-(1.0/(double)p));
                }
            }
            if(n>1)
                result*=(1.0-(1.0/(double)n));
            return (ll)result;
        }

        void solve()
        {
            ll n,i,m=1e9+7,j,x,ans=0,s=0;
            cin>>n;
            ll a[n+5];
            cin>>a[1];
            for(i=2;i<=n;i++)
            {
                cin>>a[i];
                sum[i]=(sum[i-1]+a[i]);
            }
            //cout<<sum[n]<<endl;
            for(i=2;i<=n;i++)
            {
                ans=(sum[n]-sum[i-1])%m;
                ans=(ans*a[i-1])%m;
                ans=ans%m;
                s=(s+ans)%m;
                //cout<<s<<endl;
            }
            cout<<s%m;



        }



};
int main()
{
    Myfirst *prg = new Myfirst();
    prg->solve();
}


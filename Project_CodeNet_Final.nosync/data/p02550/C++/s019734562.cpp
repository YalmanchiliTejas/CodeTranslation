#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 998244353
#define dd double
#define vi vector<int>
#define vll vector<ll>
#define forr(i, n) for(ll i=0;i<n;i++)
#define revf(i,n) for(ll i=n-1;i>=0;i--)
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define rep1(i,b) for(ll i=1;i<=b;i++)
#define inp(a,n) for(ll i=0;i<n;i++)cin>>a[i]
#define outp(a,n) for(ll i=0;i<n;i++)cout<<a[i]<<" "
#define outp1(a,n) for(ll i=1;i<n;i++)cout<<a[i]<<" "
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) (((a)*(b))/gcd((a),(b)))
#define pb push_back
#define mp make_pair
#define mem(x,n) memset(x,n,sizeof(x))
#define BINSC binary_search
#define BITOUT __builtin_popcount
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define test ll t; cin>>t; while(t--)
#define cn cout<<"\n";
int main()
{
     ll n,x,m;
     cin>>n>>x>>m;
     ll a=x;
     ll out=a;
     set<ll>s;
     ll j=-1,k=-1;
     vll v;
     v.pb(a);
     forr(i,n-1)
     {
          a=(a*a)%m;
          ll size=s.size();
          s.insert(a);
          if(size==s.size())
          {
               j=i;k=a;break;
          }
          else
          {
               v.pb(a);
               out+=a;
          }
     }
     if(j==-1)
          cout<<out;
     else
     {
          j++;
          ll j1=-1;
          forr(i,v.size())
          {
               if(v[i]==k)
               {
                    j1=i;
                    break;
               }
          }
          ll sum=0;
          for(ll i=0;i<j1;i++)
               sum+=v[i];
          ll diff=(j-j1);
          ll q=(n-j1)/diff;
          ll w=(n-j1)%diff;
          //cout<<sum<<" "<<q-1;cn
          out=out+(out-sum)*(q-1);
          //cout<<out;cn
          for(ll i=j1;i<w+j1;i++)
               out+=v[i];
          cout<<out;
     }
}
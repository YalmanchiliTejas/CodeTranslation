#include<bits/stdc++.h>
#define mp make_pair
#define ss second
#define ff first
#define ll long long
#define tcase ll t;cin>>t;while(t--)
#define sz(a) int((a).size())
#define pb push_back
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define Yes cout<<"Yes\n";
#define No cout<<"No\n";
#define yes cout<<"yes\n";
#define no cout<<"no\n";
#define f(i,a,b) for(int i=a;i<b;i++)
#define in insert
#define matrix vector<vector<ll> >
#define E cout<<"\n";
#define I(x) cin>>x;
#define O(x) cout<<x;
#define all(a) a.begin(),a.end()
#define vi vector<int>
const ll M=1000000007;
const double pi=3.1415926;

using namespace std;

//ll modexpo(ll a,ll b,ll p)
//{
//    ll ans=1;
//      a=a%p;  // update a if(a>=p)
//
//        if(a==0)
//            return 0;
//
//                while(b!=0)
//                {
//                    if(b%2==1)
//                        ans=(ans*a)%p;
//
//                    a=a*a;
//                    b=b/2;
//
//                }
//                return ans;
//}

//ll countbit(ll n)
//{
//    ll c=0,x=0;
//    while(n!=0)
//    {
//        c+=n&1;
//        n>>=1;
//        x++;
//    }
//    return c==x;
//}



/*  vector<int> prime1;
  int prime[10000001];

void sieve(int n)
{
       for(long long i=2;i<=n;i++)
       {
         if(prime[i]==0)
         {  prime[i]=i;
            prime1.pb(i);
         }

            for(long long j=0;j<sz(prime1) && prime1[j]<=prime[i] && i*prime1[j]<=n;j++)
            {

                   prime[i*prime1[j]]=prime1[j];


            }


      }

 return ;
}*/

void fastio()
{
       ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

}
//ll gcd(ll a,ll b)
//{
//    if(a==0)
//        return b;
//    else
//        return gcd(b%a,a);
//}



int main()
{
    fastio();
     int n;
     cin>>n;
     if(n>=30)
        Yes
      else
      No
    return 0;
}

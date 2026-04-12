#include<bits/stdc++.h>
#define fi                first
#define se                 second
#define ll               long long
#define mod              1000000007
#define endl              "\n"
#define fast               ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb                push_back
#define all(v)             v.begin(),v.end()
#define inp(V,n)      for(int i=0;i<n;i++){cin >> V[i];}
#define oup(V,n)     {for(int i=0;i<n;i++){cout <<  V[i] << " "  ;} cout << endl;}
#define pll              pair<long long,long long>
using namespace std;
ll factorial(ll n)
{
    return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
}
ll gcd(ll a, ll b)
{
    if (a == 0)
      return b;
    return gcd(b % a, a);
}
ll lcm(ll a, ll b)
{
   return (a*b)/gcd(a, b);
}
bool sortByVal(const pair<double,double> &a,
              const pair<double,double> &b)
{
    if(a.fi==b.fi)
    {
    return (a.se >b.se);
    }
    else
        return (a.fi<b.fi);
}
ll Powb(ll b,ll n)
{
    if(n==0) return 1LL;
    if(n==1) return b;
    ll temp = Powb(b,n/2);
    if(n%2==0){return (temp*temp)%mod;}
    else{return (b*((temp*temp)%mod))%mod;}
}
int main()
{
 fast;
     int t=1;
     //cin>>t;
     while(t--)
     {
       ll k,n,i=0,j=0,c=0,d=0,e=0,f=0,g=0,h=0,maxi=0,sum=0;
         cin>>n;
         if(n>=30)
            cout<<"Yes"<<endl;
         else
            cout<<"No"<<endl;

     }
}

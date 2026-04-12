#include<bits/stdc++.h>
#define ll             long long int
#define lb             lower_bound
#define ub             upper_bound
#define fi             first
#define mp             make_pair
#define vll            vector<ll>
#define se             second
#define sz             size()
#define mod            1000000007

#define fast           ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define allr(v)        v.rbegin(),v.rend()
#define inp(V,n)       for(int i=0;i<n;i++){cin >> V[i];}
#define oup(V,n)       {for(int i=0;i<n;i++){cout <<  V[i] << " "  ;} cout << endl;}
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
    return (a.second >b.second);
    }
    else
        return (a.fi<b.fi);
}


int main()
{
   ll q=1;
   //cin>>q;
   while(q--)
   {
        ll n,m,i,j,k,l,r,sum=0,b,c=0,d,ans=0;
         cin>>n;
         if(n>=30)
            cout<<"Yes"<<endl;
         else cout<<"No"<<endl;

   }
   return 0;
}

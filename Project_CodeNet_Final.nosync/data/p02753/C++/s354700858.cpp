//AUTHOR: RAVAN_2070
//PUNE INSTITUTE OF COMPUTER TECHNOLOGY
/*
        PEOPLE'S LIVES DON'T END WHEN THEY DIE.
        IT ENDS WHEN THEY LOSE FAITH
                                     -ITACHI UCHIHA
        EXPLAINATION BELOW->
*/
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<pair<ll,ll>> vii;
typedef pair<ll,ll> pii;
typedef map<ll,ll> mii;
#define MOD7 1000000007
#define MOD9 1000000009
#define pi 3.1415926535
#define Test_cases ll TC;cin>>TC;while(TC--)
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()
#define sp(x) fixed<<setprecision(x)
#define sz(x) (ll)(x.size())
ll gcd(ll a,ll b);
ll lcm(ll a,ll b);
ll modularExponentiation(ll x,ll n,ll M);
void dsp(vector<ll> &V);
void dsp2(vector<pair<ll,ll>>&V);
void dsp3(map<ll,ll>&M);
double fact(double n);
ll nPr(ll n,ll r);
ll nCr(ll n,ll r);
ll r[40001];
ll c[40001];
void solve()
{
   string s;cin>>s;
   ll a,b,i;
   a=b=0;
   for(i=0;i<sz(s);i++)
   {
       if(s[i]=='A')a++;
       else b++;
   }
   if(a==0||b==0)
       cout<<"No\n";
   else
       cout<<"Yes\n";
}
int main()
{
   fastio
    solve();
  return 0;
}
ll gcd(ll a,ll b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
          
} 
ll lcm(ll a,ll b)  
{  
    return (a*b)/gcd(a, b);  
}  
ll modularExponentiation(ll x,ll n,ll M)
{   
    ll result=1;
    while(n>0)
    {
        if(n % 2 ==1)
        result=(result * x)%M;
        x=(x*x)%M;
        n=n/2;
    }
        return result;
}
void dsp(vector<ll> &V)
{
    ull j;
    for(j=0;j<V.size();j++)
    {
        cout<<V[j]<<" ";
    }
    cout<<endl;
}
void dsp2(vector<pair<ll,ll>>&V)
{
    ull j;
    for(j=0;j<V.size();j++)
    {
        cout<<V[j].first<<" "<<V[j].second<<" ";
    }
    cout<<endl;
}
void dsp3(map<ll,ll>&M)
{
      map<ll,ll>::iterator it=M.begin();
      while(it!=M.end())
      {
        cout<<it->first<<" "<<it->second<<endl;
        it++;
      }
}
double fact(double n)
{
    double i=1;
    double res=1;
    
    if(n==0)
        return 1.00;
    
    while(i<=n)
    {
        res*=i;
        i++;
    }
    
    return res;
}
ll nPr(ll n,ll r)
{
    return (fact(n)/fact(n-r));
}
ll nCr(ll n,ll r)
{
    return (fact(n)/(fact(r)*fact(n-r)));
}
//map<ll,ll,greater<int>> to sort in descending order ,in iterator declaration no greater<int>
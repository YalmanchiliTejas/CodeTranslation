/****************************************************************************************************
                                        SUBMITTED BY-

                                                AISH_07

****************************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long
#define sl set<ll>
#define vs vector<string>
#define pb push_back
#define vl vector<ll>
#define vi vector<int>
#define PI  3.14159265
#define mod 998244353
ll a[51];
ll p[51];
ll f(ll n,ll x)
{
    if(x==0)
        return 0;
    else if(n==0)
        return 1;
    else if(x<=1+a[n-1])
        return f(n-1,x-1);
    else
        return p[n-1]+1+f(n-1,x-a[n-1]-2);
}
int main()
{
 ll n,x;
 cin>>n>>x;
 a[0]=1;
 a[1]=5;
 p[0]=1;
 p[1]=3;

 for(int i=2;i<=n;i++)
 {
     a[i]=2*a[i-1]+3;
     p[i]=2*p[i-1]+1;
 }
 cout<<f(n,x)<<"\n";

return 0;
}

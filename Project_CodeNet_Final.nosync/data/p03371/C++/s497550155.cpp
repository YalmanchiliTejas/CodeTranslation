#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
#define pb push_back
#define f(i,n) for(i=0;i<n;i++)
#define F(i,a,b) for(i=a;a<=b;i++)
#define arr(a,n) for( i=0;i<n;i++)cin>>a[i];
#define fi first
#define se second
#define mp make_pair
#define mod 1000000007
#define YES cout<<"YES"<<endl;
#define Yes cout<<"Yes"<<endl;
#define NO cout<<"NO"<<endl;
#define No cout<<"No"<<endl;
#define yes cout<<"yes"<<endl;
#define no cout<<"no"<<endl;
#define vi vector<ll>
#define ed end()
#define bg begin()
#define sz size()
#define ln length()
#define s() sort(a,a+n);
#define sr() sort(a,a+n,greater<ll>());
#define v()  sort(v.begin(),v.end());
#define vr() sort(v.begin(),v.end(),greater<ll>());
#define mod 1000000007
#define fast() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
ll gcd(ll a, ll b){if(!b)return a;return gcd(b, a % b);}
ll power(ll x,ll y,ll p){ll res=1;x%=p;while(y>0){if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}return res;}
int main() {
    /*#ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        freopen("output.txt", "w", stdout);
    #endif*/
        

fast();
//ll t;cin>>t;while(t--)
{
    ll a,b,c,x,y,n=3;
    cin>>a>>b>>c>>x>>y;
    ll arr[3];
    arr[0]=a*x + b*y;
    arr[1]=max(x,y)*2*c;
    if(x==y)
    {
      arr[2]=arr[1];
    }
    else if(x<y)
    {
      ll ans=x*2*c;
      ll temp=y-x;
      ans+=(temp*b);
      arr[2]=ans;
    }
    else if(y<x)
    {
      ll ans=y*2*c;
      ll temp=x-y;
      ans+=(temp*a);
      arr[2]=ans;
    }
    sort(arr,arr+n);
    cout<<arr[0]<<endl;
}
return 0;
}
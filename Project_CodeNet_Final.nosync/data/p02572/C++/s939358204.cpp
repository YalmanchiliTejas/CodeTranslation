#include<iostream>                          
#include<vector>                    
 #include<bits/stdc++.h>

#define mod 1000000007
#define pi 3.14159265358979
#define  PRE(x,p) cout<<setprecision(x)<<p; 
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define high INT_MAX
#define low INT_MIN
#define ll long long int
using namespace std;
ll z;
ll a[500005];
vector<ll>v; 
// cout<<"CASE #"<<z<<": "<<""<<endl;
void solve() 
{ 
  ll n,i;
  cin>>n;
   ll pre[500005];
  for(i=1;i<=n;i++)
 { cin>>a[i];
  pre[i]=0;}
  
  for(i=1;i<=n;i++)
  {
          pre[i]=(pre[i-1]+a[i])%mod;
  }
  ll ans=0;
  for(i=n;i>=2;i--)
  {
         ans=(ans+(pre[i-1]*a[i])%mod)%mod; 
  }
  cout<<ans%mod;
  
 
}
 
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
ll t=1;
//cin>>t;
for(z=1;z<=t;z++)
solve();
 
return 0;
}
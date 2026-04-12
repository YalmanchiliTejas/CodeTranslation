#include<bits/stdc++.h>
using namespace std; 
#define all(c) c.begin(),c.end()
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define tr(container,it) \
for(auto it=container.begin();it!=container.end();++it)
typedef long long ll ; 
typedef vector<int> vi;
#define mod 1000000007 

int main()
{
  //  freopen("input.txt","r",stdin);
   ios::sync_with_stdio(0);
   // cin.tie(0);
  ll n;
  cin>>n;
vector<ll>v(n);
   REP(i,0,n-1)
   cin>>v[i];
 //  sort(all(v));
vector<ll>pre(n);
pre[0]=v[0];
for(ll i=1;i<n;++i)
pre[i]=(pre[i-1]%mod+v[i]%mod)%mod;
ll sum=0;
for(ll i=1;i<n;++i)
sum=(sum+((v[i]%mod)*(pre[i-1]%mod))%mod)%mod;
cout<<sum;



    return 0;
}
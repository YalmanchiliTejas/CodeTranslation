/*
17/10/2017
*/
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
ll n,x,m;
cin>>n>>x>>m;
ll ans=0;
ll k=x%m;
ans+=k;
n--;
vector<ll> vc;
vc.push_back(ans);
map<ll,ll> mp;
mp[k]=1;
int cnt=0;
while(n>0)
{
k=(k*k)%m;
//cnt++;
//if(k==10000)
//{
//cout<<cnt<<endl;
//}
if(mp.count(k))
{
ll l=n/(vc.size()-mp[k]+1);
if(mp[k]==1)
{
ans+=(vc[vc.size()-1])*l;
}
else
{
ans+=(vc[vc.size()-1]-vc[mp[k]-2])*l;
}
n%=(vc.size()-mp[k]+1);
//cout<<ans<<endl;
break;
}
else
{
n--;
}
ans+=k;
vc.push_back(ans);
mp[k]=vc.size();
}
k=vc[vc.size()-1]-vc[vc.size()-2];
while(n>0)
{
k=(k*k)%m;
ans+=k;
n--;
}
cout<<ans;
}
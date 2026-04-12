#include<bits/stdc++.h>
#define mod 1000000007
#define mod1 998244353
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long int li;
typedef unsigned long long int ull;
using namespace std;
bool sortbysec(const pair<li,li>&a,const pair<li,li>&b)
{
    return (a.second<b.second);
}
li mpow(li x,li y)
{
  li ans=1;
  while(y)
  {
    if(y%2!=0)
    ans=((ans%mod)*(x%mod))%mod;
    y/=2;
    x=((x%mod)*(x%mod))%mod;
  }
  return ans;
}
int main()
{
fast_io
string s;
cin>>s;
li a[2]={0};
for(li i=0;i<3;i++)
a[s[i]-'A']++;
if((a[0]==0)||(a[1]==0))
cout<<"No";
else
cout<<"Yes";

  return  0;
}

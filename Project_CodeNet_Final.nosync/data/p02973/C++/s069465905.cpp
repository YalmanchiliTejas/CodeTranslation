#include <cstdlib>
#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include<cmath>
#define ll long long
const ll INF=0x3f3f3f3f;
#define mod 1000000007
#define mem(a,b) memset(a,b,sizeof(a))
#define  INF 0x3f3f3f3f
//__builtin_popcount
using namespace std;
//priority_queue
const ll MAX=100000;
ll gcd(ll a,ll b)
{
    return b==0?a:gcd(b,a%b);
}
ll kc(ll a,ll b)
{
    ll c=1;
    while(b)
    {
        if(b&1)c=(c*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return c;
}

ll F[100003];
ll Find(ll a)
{
    return F[a]<0?a:F[a]=Find(F[a]);
}
ll same(ll a,ll b)
{
    if(Find(a)==Find(b))return 1;
    return 0;
}
void up(ll a,ll b)
{
    ll x,y;
    x=Find(a);
    y=Find(b);//cout<<F[x]<<" "<<F[y]<<endl;
    if(x!=y)
        F[y]+=F[x],F[x]=y;


}
int a[100003],b[200003];
set<int>q;
int main()
{
  int n;
  cin>>n;
  for(int i=1;i<=n;i++)
   scanf("%d",&a[i]);
   int sum=0;
 for(int i=1;i<=n;i++)
 {
      if(sum==0)
      {
          b[sum++]=-a[i];
      }
      else {

        int z=upper_bound(b,b+sum,-a[i])-b;
        if(z!=sum)
        {
            b[z]=-a[i];
        }
        else {
            b[sum++]=-a[i];
        }
      }
 }
  cout<<sum;
}

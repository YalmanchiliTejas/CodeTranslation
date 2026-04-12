#include<iostream>
#include<cstring>
//#include<bits/stdc++.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstdio>
#include<map>
#include<set>
#define  si(a)       scanf("%d",&a)
#define  sl(a)       scanf("%lld",&a)
#define  sii(a,b)    scanf("%d%d",&a,&b)
#define  sll(a,b)    scanf("%lld%lld",&a,&b)
#define  queues      priority_queue
#define mod 1000000007
#define mem(a)  memset(a,0,sizeof(a));
#define def(a) ((a)&(-a))
#define fi  first
#define se  second
#define mp  make_pair
#define  pb push_back
typedef long long ll;
//priority_queue<int,vector<int >,greater<int > >q;
const ll INF=0x3f3f3f3f;
const double E=exp(1);
const double PI=acos(-1);
using namespace std;
ll kc(ll a,ll b)
{
    ll c=1;
    while(b)
    {
        if(b&1)c*=a;
        a*=a;
        b>>=1;
    }return c;
}
ll gcd(ll a,ll b)
{
    return b==0?a:gcd(b,a%b);
}
int s[200003];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
   int n,a[30],b[30],sum;sum=0;
   cin>>n;
   for(int i=1;i<=n;i++)
    cin>>a[i];
    int Max=0;
   for(int i=1;i<=n;i++)
   {
      if(a[i]>=Max)
      {
          sum++;
      }
      Max=max(Max,a[i]);
   }
   cout<<sum<<endl;
}
/******************************************
**        **             ********       **
**       ** **           **             **
**      **   **          **             **
**     **     **         **             **
**    ***********        **             **
**   **         **       ********       **
******************************************/

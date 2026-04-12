#include<bits/stdc++.h>
#define INF 2147483647
#define  ll long long
using namespace std;
const int Max=2e5+20;
const int Maxn=1e7+20;
const int mod=1e9+7;
inline int read()
{
    int f=1,x=0;
    char ch;
    do
    {
        ch=getchar();
        if(ch=='-')f=-1;
    }
    while(ch<'0'||ch>'9');
    do
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    while(ch>='0'&&ch<='9');
    return x*f;
}
ll a[Max];
ll sum[Max];
int main()
{

   int n;
   cin>>n;
   for(int i=1;i<=n;i++)
    {a[i]=read();
    sum[i]=sum[i-1]+a[i];
    }
   ll ans=0;
   for(int i=1;i<n;i++)
   {
       ans+=(((sum[n]-sum[i])%mod)*a[i])%mod;
       ans%=mod;
   }
   cout<<ans<<endl;

}



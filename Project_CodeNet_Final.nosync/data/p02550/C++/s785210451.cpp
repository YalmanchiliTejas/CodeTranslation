#include <bits/stdc++.h>
#define ll  long long
#define ull unsigned long long  
using namespace std;
#define  inf 1e18+18
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define mod 1000000007
#define  f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n)  for(i=0;i<n;i++)
#define w(x)   while(x--)
const int maxn=1000001;
#define  pq priority_queue
#define  ff first
#define  ss second 
#define pb  push_back
#define lb lower_bound
int db(int n)
{
    int i=0;
    int j=0;
    while(n>0)
    {
        int r=n%10;
        n=n/10;
        j+=(1<<i)*r;
        i++;
    }
    return j;
}
ll a[maxn];
int main()
{
   
    
   
  ll int n,i,j,l=0,m,x,res=0;
   cin>>n>>x>>m;
  vector<ll>v;
  int ch=0;
  l=0;
   for (i=1;i<=min(n,(ll)50000);i++)
   {
    //cout<<x%m<<" " ;
    x=x%m;

    if(v.empty())
    v.pb(x);
   else
   {
     for(int i1=0;i1<v.size();i1++)
     {
        if(v[i1]==x)
        {
            l=i-1;
            j=i1;
            ch=1;
            break;
        }
     }   
     if(ch)
        break;
     v.pb(x);
   }
   res+=x;
   
   // x=x%m;
    x=(x*x)%m;
   }
  // cout<<l<<" "<<j<<" "<<ch;
   if(ch){
   n=n-l;
   int c=0;

   for(i=j;i<v.size();i++)
   {
    c++;
   }
   for(i=j;i<v.size();i++)
   {
       ll int p=n/c;
       res+=p*v[i];
   }
   for(i=j;i<min((ll)v.size(),j+n%c);i++)
   {
    res+=v[i];
   }
}
   cout<<res;

  

}
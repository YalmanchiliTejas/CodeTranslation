#include<bits/stdc++.h>
#include <unistd.h>
#define lg long long int
#define loop(i,s,e) for(lg i=s;i<=e;i++)
#define iloop(i,s,e) for(lg i=e;i>=s;i--)
#define pb push_back
#define mp make_pair
using namespace std;

lg min(lg a,lg b)
{return a<b?a:b;}
lg max(lg a,lg b)
{return a>b?a:b;}
lg lcm(lg a ,lg b)
{
    return (a*b)/__gcd(a,b);
}
int main()
{
    lg n,x,m;
    cin>>n>>x>>m;
    lg now=x;
    lg ans=x;
    lg in=0;
    bool p = false;
    vector<vector<lg>>past(max(x,m)+1,vector<lg>(2,-1));
    past[x][0] = 0;
    past[x][1] = 0;
    for(lg i=1;i<n;i++)
    {
       now = (now*now)%m;
       if(now == 0)
       {
           break;
       }
       
       if(past[now][0]!=-1)
       {
           lg len = i-past[now][0];
           lg nums = (n-i)/len;
           ans+=nums*(ans-past[now][1]);
           i+=nums*len;
           in=i;
           p=true;
           break;
       }
       else
       {
            past[now][0] = i;
            past[now][1] = ans;
       }
       ans+=now;
    }
    if(p && in<n)
    {
        ans+=now;
        for(lg i=in+1;i<n;i++)
        {
           now = (now*now)%m;
           ans+=now;
        }
    }

    cout<<ans<<endl;
}

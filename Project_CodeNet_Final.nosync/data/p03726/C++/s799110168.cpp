#include<bits/stdc++.h>
#define up(j,k,i) for(i=j;i<k;i++)
#define down(j,k,i) for(i=j;i>k;i--)
#define pp(n) printf("%lld\n",n)
#define ps(s) printf("%s",s)
#define is(n) scanf("%lld",&n)
#define ips(n) scanf("%lld",n)
#define ss(s) scanf("%s",s)
#define cool 0
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define f(i) cout<<i<<endl;
#define pll pair<lld,lld> 
#define pi acos(-1)
#define dg(x) cout<<#x<<' '<<x<<endl;
#define dg2(x,y) cout<<#x<<' '<<x<<' '<<#y<<' '<<y<<endl;
#define dg3(x,y,z) cout<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<endl;
#define ds(n,m) scanf("%lld %lld",&n,&m)
#define ts(n,m,k) scanf("%lld %lld %lld",&n,&m,&k)
typedef long double ld;
typedef long long int lld;
using namespace std;
const lld M =1e5+7;
const lld mod=1e9+7;
const lld infi =LLONG_MAX;
lld i,j,ans,k,n,x,y,m,mymax=LLONG_MIN,mymin=LLONG_MAX,b,c,z,sum;
vector<lld> v[M],level[M];
lld parent[M],visit[M];
lld dfs(lld node,lld cnt)
{ 
  visit[node]=1;
  level[cnt].pb(node);
  for(auto ll:v[node])
  {
    if(visit[ll]==0)
    {
      parent[ll]=node;
      dfs(ll,cnt+1);
    }
  }
  mymax=max(mymax,cnt);
}
int main()
{
    is(n);
    parent[n]=n;
    up(0,n-1,i)
    {
      ds(x,y);
      parent[i+1]=i+1;
      v[x].pb(y);
      v[y].pb(x);
    }
    dfs(1,1);
    lld max_level=mymax;
    up(0,n+1,i)visit[i]=0;
    while(max_level>=2)
    {
      for(auto kk:level[max_level])
      {
        if(visit[kk]!=1)
        { 
       //   dg3(kk,parent[kk],visit[parent[kk]]);
          if(visit[parent[kk]]!=1)
          {
            visit[parent[kk]]=1;
          }
          else
          {
            cout<<"First\n";
            return 0;
          }
          visit[kk]=1;
        }
      }
      max_level--;
    }
    up(1,n+1,i)
    {
      if(visit[i]!=1)
      {
        cout<<"First\n";
        return 0;
      }
    }  
    cout<<"Second\n";
    return 0;
}
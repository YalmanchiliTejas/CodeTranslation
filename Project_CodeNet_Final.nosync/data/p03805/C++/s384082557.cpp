#include<bits/stdc++.h>
#include<sstream>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
#define mod 1000000007
#define all(v) v.begin(),v.end()
#define loop(i,a,b) for(i=(int)a;i<(int)b;i++)
#define revloop(i,a,b) for(i=(int)a;i>=(int)b;i--)
#define stloop(it,v) for(it=v.begin();it!=v.end();++it)
#define ii pair<int,int>
#define MP make_pair
#define pb push_back
#define ll long long int
#define INF 1000000005
#define PI acos(-1.0)
#define f first
#define s second
int ans,target;
vector<vector<int> > adj;
void go(int pos,int mask)
{
  if(mask == target)
  {
   ans++;
   return;
  }
  for(auto &it:adj[pos])
  {
    if(!(mask & (1<<it)))
      go(it,mask | (1<<it));
  }
}
int main()
{  std::ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   int n,m,i,a,b;
   cin>>n>>m;
   adj.resize(n);
   loop(i,0,m)
   { cin>>a>>b;
     a--;
     b--;
     adj[a].pb(b);
     adj[b].pb(a);
   }
   target = (1<<n)-1;
   go(0,1);
   cout<<ans;
   return 0;
}

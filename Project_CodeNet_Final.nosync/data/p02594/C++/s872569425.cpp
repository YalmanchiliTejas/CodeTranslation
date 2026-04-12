#include <bits/stdc++.h>
using namespace std;
typedef long long int  ll;


#define MAXN 100005
vector <ll> V[MAXN]; 
ll depth[MAXN];


void boost()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);  
}


void dfs(ll cur, ll prev) 
{ 
    ll i,j;
    
    depth[cur]=depth[prev]+1;

    for (i=0; i<V[cur].size(); i++) 
    { 
        if (V[cur][i] != prev) 
        {
            dfs(V[cur][i], cur);
            
        }
    }
} 

int main()
{
    boost();
 
    ll i,j,k,n,z,t,l,r,x,y,d=0,u,v,c=0;
    
  cin>>x;
  
  if(x>=30)
  {
cout<<"Yes"<<endl;
  }
  
  else 
  {
    cout<<"No"<<endl;
  }


return 0;
}

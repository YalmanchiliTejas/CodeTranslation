#include<bits/stdc++.h>
#include<bitset>
#include<string>
using namespace std;
#include <numeric> 
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using pi=pair<long long,long long>;
#define pii 3.1415926536
#define binary
#define mod 1000000007
typedef long long ll;
typedef long double ld;
bool sortbysec(const pair<long long,long long> &a, 
              const pair<long long,long long> &b) 
{ 
    return (a.first < b.first); 
}
bool compare(const pair<pair<ll,ll>,ll> &a,const pair<pair<ll,ll>,ll>&b)
{
    if(a.first.first==b.first.first)return (a.first.second<b.first.second);
    return (a.first.first < b.first.first); 
}
 int lcm(int a, int b)  
 {  
    return (a*b)/__gcd(a, b);  
 }  
 int Kad(ll dp[],ll n)
{
  ll curr_max=0,maxx=INT_MIN;
  for(int i=0;i<n;i++)
  {
    curr_max=curr_max+dp[i];
    if(curr_max>maxx)
      maxx=curr_max;

    if(curr_max<0)
      curr_max=0;
   
  }

  return maxx;
}

/*void dfs(int u)
{
    vis[u]=true;
    //cout<<u<<" ";
    std::vector<ll> ::iterator i;
     for (i = g[u].begin(); i != g[u].end(); ++i) 
        if (!vis[*i]) 
            dfs(*i); 
    for(int i=1;i<g[u].size();i++)
    {
        if(!vis[g[u][i]])
        {
            dfs(i);
        }
    }
}*/


int main(){
    IOS;
    
   ll n;
   cin>>n;
   if(n>=30)
    cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define pb push_back
#define fr(i,n) for(int i=0;i<n;i++)
#define Fr(i,n) for(int i=0;i++<n;)
#define ifr(i,n) for(int i=n-1;i>=0;i--)
#define iFr(i,n) for(int i=n;i>0;i--)
int n,m,a,b,dp[10][1<<9]={},ans=0;
bool f[10][1<<9]={};
vector<int> e[10];
int pn(int i,int s){
  if(f[i][s]) return dp[i][s];
  f[i][s]=1;
  for(auto it=e[i].begin();it!=e[i].end();it++){
    if((s>>*it)&1) dp[i][s]+=pn(*it,s-(1<<i));
  }
  return dp[i][s];
}

int main(){
  f[0][1]=1;dp[0][1]=1;
  cin>>n>>m;
  fr(i,m){cin>>a>>b;e[--a].pb(--b);e[b].pb(a);}
  fr(i,n) ans+=pn(i,(1<<n)-1);
  cout<<ans<<endl;
}
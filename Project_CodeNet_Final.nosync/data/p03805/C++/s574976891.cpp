#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define BIG 1000000010
#define repi(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) repi(i,0,n)
#define repn(i,n) for(int i=n;i>=0;i--)
typedef long long int ll;

int n,m;
int ans=0;
int g[8][8];
int c[8]={1,0,0,0,0,0,0,0};

void solve(int p,int cnt){
  if(cnt==n) ans++;
  else{
    rep(i,n){
      if(g[i][p]==1 && c[i]==0){
	c[i]=1;
	solve(i,cnt+1);
	c[i]=0;
      }
    }
    
  } 
}


int main(){
  cin>>n>>m;
  rep(i,8){
    rep(j,8) g[i][j]=0;
  }
  int a,b;
  rep(i,m){
    cin>>a>>b;
    g[a-1][b-1]=g[b-1][a-1]=1;
  }
  solve(0,1);
  cout<<ans<<endl;
  return 0;
}





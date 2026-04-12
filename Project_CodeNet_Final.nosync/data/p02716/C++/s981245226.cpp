#include<bits/stdc++.h>
#define INF 9003372036854775807LL
#define mod 998244353
#define SYOU(x) fixed<<setprecision(x+1)
#define abs(x,y) (max(x,y)-min(x,y))
#define lol long long
#define mp make_pair
#define fi first
#define se second
using namespace std;
using pii=pair<int, int > ;
lol n,m,k;
lol a[200010];
lol mem[200020][4];
lol dp(int k,int E){
  if(E<0) return -INF;
  if(mem[k][E]!=-INF) return mem[k][E];
  if(k+E==n-1) return mem[k][E]=a[k];
  lol sum=a[k];
  sum+=max(dp(k+2,E),max(dp(k+3,E-1),dp(k+4,E-2)));
  return mem[k][E]=sum;
}
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s,w;
  cin >>n;
  for(int i=0;i<n;i++){
    cin >>a[i];
  }
  for(int i=0;i<=n;i++){
    mem[i][0]=mem[i][1]=mem[i][2]=mem[i][3]=-INF;
  }
  if(n%2!=0) cout <<max(dp(0,2),max(dp(1,1),dp(2,0)))<<'\n';
  else cout <<max(dp(0,1),dp(1,0))<<'\n';
  return (0);
}

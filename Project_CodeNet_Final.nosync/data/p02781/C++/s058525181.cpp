#include<bits/stdc++.h>
#define INF 9223372036854775807LL
#define inf 1000000007
#define SYOU(x) setprecision(x+1)
#define abs(x,y) (max(x,y)-min(x,y))
#define lol long long
#define mp make_pair
#define fi first
#define se second
using namespace std;
string N;
int D;
lol dp[101][2][5];
lol rec(int k,bool fight,int one){
  if(k==N.size()){
    if(one==D) return 1;
    else return 0;
  }
  if(dp[k][fight][one]!=-1) return dp[k][fight][one];
  if(one>D) return 0;
  int lim;
  if(fight) lim=N[k]-'0';
  else lim=9;//int lim=(fight ? N[k]-'0' : 9);
  lol ret=0;
  for(int d=0;d<=lim;d++){
    if(d==0) ret+=rec(k+1,(fight && (d==lim)),one);
    else ret+=rec(k+1,(fight && (d==lim)),one+1);
  }
  return dp[k][fight][one]=ret;
}
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    memset(dp,-1,sizeof(dp));
    cin >>N;
    cin >>D;
    cout <<rec(0,true,0)<<'\n';
    return (0);
}

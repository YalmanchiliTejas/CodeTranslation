#include <bits/stdc++.h>
#define time efsfdsf
using namespace std;
typedef long long ll;
struct dats{ll x,y,p[10];};
struct datp{ll v,p;}; 
int n,m,W,T;
map<string,int>M;
dats shop[10];
datp prod[10];
vector<ll> time(1<<10,1e9);
void Min(ll &a,ll b){a=min(a,b);}
void Max(ll &a,ll b){a=max(a,b);}
int dis(int a,int b){return abs(shop[a].x-shop[b].x)+abs(shop[a].y-shop[b].y);}

void calc_time(int bit,ll cost,int pre){
  for(int i=0;i<n;i++){
    if(bit&(1<<i))continue;
    int nbit = bit|(1<<i);
    ll ncost = cost+dis(i,pre);
    Min(time[nbit],ncost+dis(i,n));
    calc_time(nbit,ncost,i);
  }
}

ll dp[1<<7][10010];
void calc_w(){
  for(int i=0;i<(1<<n);i++){
    vector<ll> p(10,1e9);
    for(int j=0;j<n;j++)
      if(i&(1<<j))for(int k=0;k<m;k++)Min(p[k],shop[j].p[k]);

    for(int j=0;j<m;j++)
      for(int k=0,w=prod[j].v;k<=W-w;k++)Max(dp[i][k+w],dp[i][k]+prod[j].p-p[j]);

    for(int j=1;j<=W;j++) Max(dp[i][j],dp[i][j-1]);
  }
}


ll DP[100010];
ll calc_p(){
  for(int i=0;i<(1<<n);i++)
    for(int k=0;k<=T-time[i];k++)Max(DP[k+time[i]],DP[k]+dp[i][W]);
  ll res=0;
  for(int i=0;i<=T;i++) Max(res,DP[i]);
  return res;
}

int main(){
  cin>>n>>m>>W>>T;
  for(int i=0,v,p;i<m;i++){
    string s;
    cin>>s>>v>>p;
    M[s]=i;
    prod[i] = (datp){v,p};
  }

  shop[n] = (dats){0,0,0};
  for(int i=0,l;i<n;i++){
    cin>>l>>shop[i].x>>shop[i].y;
    string s;
    for(int j=0;j<m;j++) shop[i].p[j] = 1e9;
    for(int j=0,p;j<l;j++)cin>>s>>p,shop[i].p[M[s]] = p;
  }
  calc_time(0,0,n);
  calc_w();  
  cout<<calc_p()<<endl;
  return 0;
}
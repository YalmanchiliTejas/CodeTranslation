#include<bits/stdc++.h>
  
#define lol long long
#define gcd(x,y) __gcd(x,y)
#define mt make_tuple
#define mp make_pair
#define fi first
#define se second
#define fixed(x) fixed<<setprecision(x)
using namespace std;
using pii=pair<int,int>;
template <class A, class B> inline bool chmax(A &a, const B &b) { return b > a && (a = b, true); }
template <class A, class B> inline bool chmin(A &a, const B &b) { return b < a && (a = b, true); }
template <class A> inline lol abs(A &a) { return (a < 0 ? -a : a); }
const lol inf=(1LL<<60);
const lol Mod=(1e9)+7;
const lol mod=998244353;
const int dx[]={1,0,-1,0,1,1,-1,-1};
const int dy[]={0,1,0,-1,1,-1,1,-1};
bool line(lol x,lol y,lol nx,lol ny){return (x<nx&&y<ny&&x>=0&&y>=0);}
lol n,m,k;
vector<int> load[10];
lol f(int place,vector<bool> vis);
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >>n>>m;
  for(int i=0;i<m;i++){
    int a,b;
    cin >>a>>b;
    load[a].push_back(b);
    load[b].push_back(a);
  }
  vector<bool> can(n+1,false);
  cout <<f(1,can)<<'\n';
  return (0);
}
lol f(int place,vector<bool> vis){
  if(vis[place]) return 0;
  vector<bool> can(n+1);
  int sum=0;
  vis[place]=true;
  for(int i=1;i<=n;i++){
    can[i]=vis[i];
    if(can[i]) sum++;
  }
  if(sum==n) return 1;
  lol ans=0;
  for(int i=0;i<load[place].size();i++){
    ans+=f(load[place][i],can);
  }
  return ans;
}

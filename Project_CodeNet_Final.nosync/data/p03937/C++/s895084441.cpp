#pragma GCC optimize ("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;
using Int = long long;
typedef pair<int,int> P; typedef pair<Int,Int> Pl;
const int mod = 1e9+7;
const Int Inf = 1e17;
#define END {cout<<ans<<'\n'; return 0;}
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
#define mp make_pair
#define Pr(t) priority_queue<t>
#define gPr(t) priority_queue<t,vector<t>,greater<t>>
#define V(t) vector<t>
#define rep(i,n) for(int(i)=0; i<n; i++)
#define rer(i,l,r) for(int i=l; i<=r; i++)
#define gnr(i,l,r) for(int i=r; i>=l; i--)
#define eb emplace_back
#define pri1(a) cout<<(a)<<'\n'
#define pri2(a,n) {rep(pri2i,n-1)cout<<a[pri2i]<<' '; if(n>1)cout<<a[n-1]<<'\n';}
#define prip(p) cout<<p.fi<<' '<<p.se<<'\n'
template<class T> inline bool cmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool cmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int n,m,_,x,y,q;
string s,sb;
bool ok;
char cf,cb;

int main(){
  cin.tie(nullptr); ios::sync_with_stdio(0);

  cin>>n>>m; bool g[n][m],seen[n][m]={};
  rep(i,n)rep(j,m){cin>>cf; g[i][j]=cf=='#';}
  queue<P>que; que.emplace(0,0); seen[0][0]=1;
  while(!que.empty()){
    tie(y,x)=que.front(); que.pop();
    if(y==n&&x==m)break;
    if(y+1<n&&g[y+1][x]&&x+1<m&&g[y][x+1]){pri1("Impossible"); return 0;}
    if(y+1<n&&g[y+1][x]&&!seen[y+1][x]){que.emplace(y+1,x); seen[y+1][x]=1;}
    if(x+1<m&&g[y][x+1]&&!seen[y][x+1]){que.emplace(y,x+1); seen[y][x+1]=1;}
  }
  ok=1;
  rep(i,n)rep(j,m)if(g[i][j])ok&=seen[i][j];
  pri1(ok?"Possible":"Impossible");
}
#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(signed i=0;i<n;++i)
#define repi(n) rep(i,n)
#define int long long
#define str string
#define vint vector<int>
#define pint pair<int,int>
#define pb(a) push_back(a)
#define all(v) v.begin(),v.end()
#define yn(b) cout<<((b)?"Yes":"No")<<endl
#define YN(b) cout<<((b)?"YES":"NO")<<endl
#define call(a) for(auto t:a)cout<<t<<" ";cout<<endl
#define ENDL printf("\n");
#define debg(a) cout<<#a<<":"<<a<<endl;
#define SORT(a) sort(all(a));
#define INF 1LL<<60
#define inf INF
#define out(i) cout<<i<<endl;
int min(int a,int b){if(a>b)return b;return a;}
int max(int a,int b){if(a>b)return a;return b;}

bool graphs[10][10];
int res;
void dfs(int s,int n,bool visited[]){
  bool all=true;
  rep(i,n)if(!visited[i])all=false;
  if(all)res++;
  rep(i,n){
    if(!graphs[s][i])continue;
    if(visited[i])continue;
    visited[i]=true;
    dfs(i,n,visited);
    visited[i]=false;
  }
}
signed main(){
  int n,m;
  cin>>n>>m;
  vint a(m),b(m);
  rep(i,m){
    cin>>a[i]>>b[i];
    a[i]--,b[i]--;
    graphs[a[i]][b[i]]=true;
    graphs[b[i]][a[i]]=true;
  }
  bool visited[n]={false};
  visited[0]=true;
  dfs(0,n,visited);
  out(res);

  return 0;
}


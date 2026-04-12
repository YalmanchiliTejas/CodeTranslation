#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }
int dx[2]={1,0};
int dy[2]={0,1};

int main() {
  int h,w;
  cin>>h>>w;
  //
  bool visited[h][w];
  rep(i,0,h)rep(j,0,w)visited[i][j]=false;
  //
  vector<string> a(h);
  rep(i,0,h) cin>>a[i];
  bool ok=true;
  ////////
  queue<P> root;
  root.push(mp(0,0));
  visited[0][0]=true;
   while(!root.empty()){
    P now=root.front();
    root.pop();
   int x=now.first;
   int y=now.second;
     //if(now==mp(w-1,h-1))break;
    rep(i,0,2){
      int nx=x+dx[i];
      int ny=y+dy[i];
     // cout<<nx<<endl;
      if(nx>=h||ny>=w) continue;
      if(a[nx][ny]=='.') continue;
      if(visited[nx][ny])continue;
      root.push(mp(nx,ny));
      visited[nx][ny]=true;  
      break;
    }  
  }
  rep(i,0,h){
   rep(j,0,w){
      if(!visited[i][j]&&a[i][j]=='#') ok=false; 
   }
  }
 // root.push(mp(h,w));
  
  if(ok){
   cout<<"Possible"<<endl;
  }
  else cout<<"Impossible"<<endl;
}
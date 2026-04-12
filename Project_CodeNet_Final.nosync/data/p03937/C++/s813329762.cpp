

#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define INF LLONG_MAX
#define ll long long
#define ull unsigned long long
#define M (int)(1e9+7)
#define P pair<int,int>
#define FOR(i,m,n) for(int i=(int)m;i<(int)n;i++)
#define RFOR(i,m,n) for(int i=(int)m;i>=(int)n;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,n,0)
#define all(a) a.begin(),a.end()
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};
#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define int ll
#define vi vector<int>
#define IP pair<int,P>
#define PI pair<P,int>
#define PP pair<P,P>
#define Yes(f){cout<<(f?"Yes":"No")<<endl;}
#define YES(f){cout<<(f?"YES":"NO")<<endl;}
#define MPlus(x,y) {x=(x+y)%M;}
#define MSub(x,y) {x=(x-y+M)%M;}
#define MMul(x,y) {x=(x*y)%M;}


bool ans=false;
int h,w;
char a[10][10];

void f(int x,int y,bool b[10][10]){

  if(x==w-1&&y==h-1){
    bool flag=true;
    rep(i,h){
      rep(j,w){
        if(a[i][j]=='#'&&!b[i][j])flag=false;
      }
    }
    ans|=flag;
    return;
  }

  if(x+1<w&&a[y][x+1]=='#'){
    b[y][x+1]=true;
    f(x+1,y,b);
    b[y][x+1]=false;
  }
  if(y+1<h&&a[y+1][x]=='#'){
    b[y+1][x]=true;
    f(x,y+1,b);
    b[y+1][x]=false;
  }
  
}


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  
  cin>>h>>w;
  rep(i,h){
    cin>>a[i];
  }

  bool b[10][10]={};
  b[0][0]=true;
  f(0,0,b);


  if(ans){
    cout<<"Possible"<<endl;
  }else{
    cout<<"Impossible"<<endl;
  }



}
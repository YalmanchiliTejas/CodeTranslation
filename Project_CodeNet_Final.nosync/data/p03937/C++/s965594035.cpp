#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
#define ll long long 
#define M 1000000007
#define P pair<int,int>
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define rep(i,n) FOR(i,0,n)
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};
#define PI 3.14159265

int h,w;
char a[10][10];
bool ans;
int d;


int main(){
  cin>>h>>w;
  rep(i,h){
    cin>>a[i];
    rep(j,w){
      if(a[i][j]=='#') d++;
    }
  }

  int b[10][10];
  rep(i,h)rep(j,w) b[i][j]=inf;

  b[0][0] = 1;
  queue<P> q;
  q.push(P(0,0));

  while(!q.empty()){
    P p = q.front(); q.pop();
    int x = p.first,y = p.second;
    if(a[y+1][x]=='#'&&b[y+1][x]>b[y][x]){
      b[y+1][x] = b[y][x]+1;
      q.push(P(x,y+1));
    }
    if(a[y][x+1]=='#'&&b[y][x+1]>b[y][x]){
      b[y][x+1] = b[y][x]+1;
      q.push(P(x+1,y));
    }
  }

  if(b[h-1][w-1]==d)
    cout<<"Possible"<<endl;
  else
    cout<<"Impossible"<<endl;

  return 0;
}

  

#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int uf[100000];

struct point{
  int x;
  int y;
};

struct X{
  int x;
  int num;
  bool operator<(const struct X & right) const{
    return x<right.x;
  }
};

struct edge{
  int c;
  int s;
  int g;
  bool operator<(const struct edge & right) const{
    return c>right.c;
  }
};

int par(int a){
  if(uf[a]==a) return a;
  else return uf[a]=par(uf[a]);
}

void uni(int a,int b){
  a=par(a);
  b=par(b);
  if(a==b) return;
  uf[a]=uf[b];
  return;
}

int main(){
  int n;
  cin >> n;
  for(int i=0;i<n;i++){
    uf[i]=i;
  }
  vector<struct point> town(n);
  vector<struct X> x(n),y(n);
  for(int i=0;i<n;i++){
    cin >> town[i].x >> town[i].y;
    x[i]={town[i].x,i};
    y[i]={town[i].y,i};
  }
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  priority_queue<struct edge> que;
  for(int i=1;i<n;i++){
    que.push({x[i].x-x[i-1].x,x[i-1].num,x[i].num});
    que.push({y[i].x-y[i-1].x,y[i-1].num,y[i].num});
  }
  struct edge now;
  LL ans=0;
  while(!que.empty()){
    now = que.top();
    que.pop();
    if(par(now.s)!=par(now.g)){
      uni(now.s,now.g);
      ans+=now.c;
    }
  }
  cout << ans << endl;
  return 0;
}

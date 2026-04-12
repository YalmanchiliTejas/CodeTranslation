#include<bits/stdc++.h>
using namespace std;
#define r(i,n) for(int i=0;i<n;i++)
typedef pair<int,int>P;
typedef pair<P,P>PP;
int dp[1<<16];
int n,a1,a2;
vector<P>v;
vector<PP>G;
string s[4],t[4],tmp[4];
string ccol="RGB";
int main(){
  memset(dp,-1,sizeof(dp));
  int a[4][4];
  r(i,4)r(j,4)a[i][j]=(i*4+j);
  cin>>n;
  r(i,n){
    cin>>a1>>a2;
    v.push_back(P(a1,a2));
  }
  r(i,4)cin>>s[i],t[i]=s[i];
  dp[0]=0;
  queue<int>q;
  q.push(0);
  r(i,4)r(j,4)r(k,n){
    P m1=P(4,4),m2=P(0,0);
    for(int y=i,c1=0;c1<v[k].first;c1++,y++){
      for(int x=j,c2=0;c2<v[k].second;c2++,x++){
        if(0<=y&&y<4&&0<=x&&x<4){
          m1=min(m1,P(y,x));
          m2=max(m2,P(y,x));
        }
      }
    }
    G.push_back(PP(m1,m2));
  }
  r(i,4)r(j,4)r(k,n){
    P m1=P(4,4),m2=P(0,0);
    for(int y=i,c1=0;c1<v[k].first;c1++,y--){
      for(int x=j,c2=0;c2<v[k].second;c2++,x--){
        if(0<=y&&y<4&&0<=x&&x<4){
          m1=min(m1,P(y,x));
          m2=max(m2,P(y,x));
        }
      }
    }
    G.push_back(PP(m1,m2));
  }
  q.push(0);
  r(i,4)for(int j=3;j>=0;j--)r(k,n){
    P m1=P(4,4),m2=P(0,0);
    for(int y=i,c1=0;c1<v[k].first;c1++,y++){
      for(int x=j,c2=0;c2<v[k].second;c2++,x--){
        if(0<=y&&y<4&&0<=x&&x<4){
          m1=min(m1,P(y,x));
          m2=max(m2,P(y,x));
        }
      }
    }
    G.push_back(PP(m1,m2));
  }
  for(int i=3;i>=0;i--)r(j,4)r(k,n){
    P m1=P(4,4),m2=P(0,0);
    for(int y=i,c1=0;c1<v[k].first;c1++,y--){
      for(int x=j,c2=0;c2<v[k].second;c2++,x++){
        if(0<=y&&y<4&&0<=x&&x<4){
          m1=min(m1,P(y,x));
          m2=max(m2,P(y,x));
        }
      }
    }
    G.push_back(PP(m1,m2));
  }
  sort(G.begin(),G.end());int rs=0;
  G.erase(unique(G.begin(),G.end()),G.end());
  while(!q.empty()){
    int p=q.front();q.pop();
    int xx=p;//if(p.second==15)return 0;
    if(xx==(1<<16)-1){
      cout<<dp[p]<<endl;
      return 0;
    }
    int xp=0;
    r(i,4)r(j,4){
      if((xx>>(i*4+j))&1)xp|=(1<<a[i][j]);
      else t[i][j]='W';
    }
    r(k,G.size()){
      int sy=G[k].first.first;
      int sx=G[k].first.second;
      int gy=G[k].second.first;
      int gx=G[k].second.second;
      for(int col=0;col<3;col++){
        int tp=xp;
        for(int i=sy;i<=gy;i++){
          for(int j=sx;j<=gx;j++){
            if(ccol[col]==s[i][j])tp|=(1<<a[i][j]);
            else if((tp>>a[i][j])&1)tp-=(1<<a[i][j]);
          }
        }
        if(dp[tp]==-1){rs++;
          dp[tp]=dp[xx]+1;
          q.push(tp);
        }
      }
    }
  }
}
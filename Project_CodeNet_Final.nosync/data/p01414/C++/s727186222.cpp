#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;

int n;
int h[16],w[16];
char t[16];
vector<P> G;
map<P,bool> used;
string str="RGB";

int d[(1<<16)];

int solve(){
  queue<int> Q;
  for(int i=0;i<(1<<16);i++)d[i]=-1;
  d[0]=0;
  Q.push(0);
  
  while(!Q.empty()){
    int S=Q.front();Q.pop();
    if(S==(1<<16)-1)return d[S];
    
    for(int i=0;i<(int)G.size();i++){
      int ay=G[i].first/5;
      int ax=G[i].first%5;
      int by=G[i].second/5;
      int bx=G[i].second%5;
      //cout<<ay<<' '<<ax<<' '<<by<<' '<<bx<<endl;
      for(int j=0;j<3;j++){
        char ch=str[j];
        int next=S;
        for(int y=ay;y<by;y++){
          for(int x=ax;x<bx;x++){
            int z=y*4+x;
            next|=(1<<z);
            if(t[z]!=ch)next-=(1<<z);
          }
        }
        if(d[next]==-1){
          d[next]=d[S]+1;
          Q.push(next);
        }
      }
    }
  }
  return -1;
}

void add(int h,int w){
  P p;
  for(int i=-h+1;i<4;i++){
    for(int j=-w+1;j<4;j++){
      int ay=max(i,0);
      int ax=max(j,0);
      int by=min(i+h,4);
      int bx=min(j+w,4);
      p.first=ay*5+ax;
      p.second=by*5+bx;
      if(used[p])continue;
      used[p]=true;
      G.push_back(p);
    }
  }
}

int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>h[i]>>w[i];
    add(h[i],w[i]);
  }

  for(int i=0;i<16;i++)cin>>t[i];
  sort(G.begin(),G.end());
  cout<<solve()<<endl;
  return 0;
}
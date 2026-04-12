#include <bits/stdc++.h>
using namespace std;

using ul=unsigned long long;
int s[500],t[500],tmp[500][500],S[500],T[500],n,bit=-1,IN;
ul ans[500][500],u[500],v[500];
template<typename T>
void fin(T a){
  cout<<a<<endl;
  exit(0);
}

struct P{int va,idx,ve,ne,al;};
bool operator <(const P &a,const P &b){return a.va<b.va;};
priority_queue<P> que;

#define REP(i,n) for(int i=0;i<n;i++)
#define F(va,ne) {\
  if((tmp[i][j]^va)==1&&ne)fin(-1);\
  if(!~tmp[i][j]){\
    ans[i][j]+=((ul)1<<bit)*(tmp[i][j]=va);\
    S[i]++,T[j]++;\
    if(IN){\
      if(S[i]<n)que.push({S[i],i,'S',s[i],1});\
      if(T[j]<n)que.push({T[j],j,'T',t[j],1});\
    }\
  }\
}
void AL(){
  bool KO=1;
  while(KO){
    KO=0;
    REP(i,n){
      if(s[i]&&((u[i]>>bit)&1)){
        bool f=0;
        REP(j,n)f|=tmp[i][j]==1;
        if(f)REP(j,n){KO|=tmp[i][j]<0;F(0,0);}
      }
      if(!s[i]&&!((u[i]>>bit)&1)){
        bool f=0;
        REP(j,n)f|=tmp[i][j]==0;
        if(f)REP(j,n){KO|=tmp[i][j]<0;F(1,0);}
      }
    }
    REP(j,n){
      if(t[j]&&((v[j]>>bit)&1)){
        bool f=0;
        REP(i,n)f|=tmp[i][j]==1;
        if(f)REP(i,n){KO|=tmp[i][j]<0;F(0,0);}
      }
      if(!t[j]&&!((v[j]>>bit)&1)){
        bool f=0;
        REP(i,n)f|=tmp[i][j]==0;
        if(f)REP(i,n){KO|=tmp[i][j]<0;F(1,0);}
      }
    }
  }
}

int main(){
  cin>>n;
  REP(i,n)cin>>s[i];
  REP(i,n)cin>>t[i];
  REP(i,n)cin>>u[i];
  REP(i,n)cin>>v[i];
  while(++bit<64){
    memset(tmp,-1,sizeof(tmp));
    memset(S,0,sizeof(S));
    memset(T,0,sizeof(T));
    IN=0;
    REP(i,n){//s側で確定マス
      if(s[i]&&!((u[i]>>bit)&1))REP(j,n)F(0,1);
      if(!s[i]&&(u[i]>>bit)&1)REP(j,n)F(1,1);
    }
    REP(j,n){//t側で確定マス
      if(t[j]&&!((v[j]>>bit)&1))REP(i,n)F(0,1);
      if(!t[j]&&(v[j]>>bit)&1)REP(i,n)F(1,1);
    }
    REP(i,n){//両側で欲しいものが一致
      REP(j,n){
        if((s[i]&&(u[i]>>bit)&1)&&(t[j]&&(v[j]>>bit)&1))F(1,0);
        if((!s[i]&&!((u[i]>>bit)&1))&&(!t[j]&&!((v[j]>>bit)&1)))F(0,0);
      }
    }
    AL();
    IN=1;
    REP(i,n)if(S[i]<n)que.push({S[i],i,'S',s[i],1});
    REP(j,n)if(T[j]<n)que.push({T[j],j,'T',t[j],1});
    while(que.size()){
      P p=que.top();que.pop();
      if(p.ve=='S'){
        int i=p.idx;
        if(p.va!=S[i])continue;
        REP(j,n){
          if(~tmp[i][j])continue;
          F(p.ne,0);
          p.ne^=p.al;p.al=0;
        }
        AL();
      }
      else{
        int j=p.idx;
        if(p.va!=T[j])continue;
        REP(i,n){
          if(~tmp[i][j])continue;
          F(p.ne,0);
          p.ne^=p.al;p.al=0;
        }
        AL();
      }
    }
  }

  REP(i,n){
    ul A=ans[i][0];
    REP(j,n)
      if(s[i])A|=ans[i][j];
      else A&=ans[i][j];
    if(A!=u[i])fin(-1);
  }
  REP(j,n){
    ul A=ans[0][j];
    REP(i,n)
      if(t[j])A|=ans[i][j];
      else A&=ans[i][j];
    if(A!=v[j])fin(-1);
  }

  REP(i,n){
    REP(j,n)cout<<ans[i][j]<<" ";cout<<endl;
  }


}

#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(i=0;i<N;++i)
#define print(v) cout<<v<<endl
#define output(v) do{bool f=0;for(auto outi:v){cout<<(f?" ":"")<<outi;f=1;}cout<<endl;}while(0)
#define matoutput(v) do{for(auto outimat:v)output(outimat);}while(0)
void startupcpp(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(15);
}

int N;
vector<int> Hf,Wf;
vector<unsigned long long> Hv,Wv;
vector<vector<int>> solve(unsigned long long bit){
  int i,j;
  bit=1LL<<bit;
  vector<bool> ch(4,false);
  vector<vector<int>> res(N,vector<int>(N,-1));
  rep(i,N){
    if(Hv[i]&bit){
      if(!Hf[i]){
        ch[0]=true;
        rep(j,N)res[i][j]=1;
      }
    }else{
      if(Hf[i]){
        ch[1]=true;
        rep(j,N)res[i][j]=0;
      }
    }
    if(Wv[i]&bit){
      if(!Wf[i]){
        ch[2]=true;
        rep(j,N)res[j][i]=1;
      }
    }else{
      if(Wf[i]){
        ch[3]=true;
        rep(j,N)res[j][i]=0;
      }
    }
  }
  if((ch[0]&ch[3])|(ch[1]&ch[2])){
    res[0][0]=-1;
    return res;
  }
  if(ch[0]&ch[1]){
    rep(i,N){
      if(res[i][0]!=-1)continue;
      rep(j,N)res[i][j]=Hf[i];
    }
    return res;
  }
  if(ch[2]&ch[3]){
    rep(i,N){
      if(res[0][i]!=-1)continue;
      rep(j,N)res[j][i]=Wf[i];
    }
    return res;
  }
  bool f=false;
  if(ch[0]&ch[2]){
    rep(i,N)rep(j,N)if(res[i][j]==-1){
      f=true;
      res[i][j]=0;
    }
    if(f)return res;
  }
  if(ch[1]&ch[3]){
    rep(i,N)rep(j,N)if(res[i][j]==-1){
      f=true;
      res[i][j]=1;
    }
    if(f)return res;
  }
  int a=0,b=0;
  rep(i,N){
    a+=res[i][0]==-1;
    b+=res[0][i]==-1;
  }
  if(!(a|b)){
    rep(i,N){
      if((!(bit&Hv[i]))==res[0][0])break;
      if((!(bit&Wv[i]))==res[0][0])break;
    }
    if(i<N)res[0][0]=-1;
    return res;
  }
  if(a==1||b==1){
    if(a==1){
      rep(i,N)if(res[i][0]==-1)break;
      if(res[(i+1)%N][0]!=Hf[i]){
        rep(j,N)res[i][j]=Hf[i];
        return res;
      }
      rep(j,N){
        res[i][j]=Wf[j];
        f|=Wf[j]==Hf[i];
      }
      if(!f)res[0][0]=-1;
    }else{
      rep(i,N)if(res[0][i]==-1)break;
      if(res[0][(i+1)%N]!=Wf[i]){
        rep(j,N)res[j][i]=Wf[i];
        return res;
      }
      rep(j,N){
        res[j][i]=Hf[j];
        f|=Hf[j]==Wf[i];
      }
      if(!f)res[0][0]=-1;
    }
  }else{
    f=ch[1]|ch[3];
    rep(i,N)rep(j,N){
      if(res[i][j]==-1){
        res[i][j]=(i==j)^f;
      }
    }
  }
  return res;
}
int main(){
  int i,j;
  unsigned long long bit;
  cin>>N;
  if(N==1){
    unsigned long long x,y;
    cin>>x>>x>>x>>y;
    if(x==y){
      print(x);
    }else{
      print(-1);
    }
    return 0;
  }
  Hf.resize(N);
  Hv.resize(N);
  Wf.resize(N);
  Wv.resize(N);
  for(auto& x:Hf)cin>>x;
  for(auto& x:Wf)cin>>x;
  for(auto& x:Hv)cin>>x;
  for(auto& x:Wv)cin>>x;
  vector<vector<unsigned long long>> ans(N,vector<unsigned long long>(N,0));
  rep(bit,64){
    vector<vector<int>> res=solve(bit);
    if(res[0][0]==-1){
      print(-1);
      return 0;
    }
    rep(i,N)rep(j,N){
      ans[i][j]|=(unsigned long long)res[i][j]<<bit;
    }
  }
  matoutput(ans);
}
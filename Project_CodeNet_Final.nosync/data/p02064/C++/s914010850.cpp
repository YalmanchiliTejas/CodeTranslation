#include<bits/stdc++.h>
using namespace::std;
using ll =long long;
#define int ll
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define INF 1000000099
template<class T> using V=vector<T>;

vector<int> finddivisor(int x){
  vector<int> d;
  for(int i=1;i*i<=x;i++){
    if(x%i==0){
      d.push_back(i);
      if(i*i!=x)d.push_back(x/i);
    }
  }
  return d;
}

int quest(int x,int y){
  cout<<'?'<<' '<<x<<' '<<y<<endl;

  int res;cin>>res;
  if(res==-1)exit(0);
  return res;

}

V<ll> dfrs,dfrt;

signed main(){
  //cin.tie(0);
  //ios::sync_with_stdio(false);
  int n,s,t;cin>>n>>s>>t;
  int sps=quest(s,t);

  dfrs.assign(n+1,INF);
  dfrt.assign(n+1,INF);
  dfrs[s]=0;
  dfrt[t]=0;


  V<int> ans(1,s);
struct comp{
  bool operator ()(int  x,int y){
    return dfrs[x]>dfrs[y];
  }  
};

  priority_queue<int,vector<int>,decltype(comp())> q;

  rep(i,1,n+1){
    if(i==s || i==t)continue;

    dfrs[i]=quest(s,i);
    dfrt[i]=quest(i,t);
    if(dfrs[i]+dfrt[i]==sps){
      q.push(i);
    }
  }
  q.push(t);

  int now=q.top();q.pop();
  ans.push_back(now);

  while(q.size()){
    int nex=q.top(),dis;
    if(nex==t)dis=dfrt[now];
    else dis=quest(now,nex);

    q.pop();

    if(dfrs[now]+dis+dfrt[nex]==sps){
      ans.push_back(nex);
      now=nex;
    }
    if(now==t)break;
  }

  cout<<'!'<<' ';
  rep(i,0,(int)(ans.size()-1)){
    cout<<ans[i]<<' ';
  }
  cout<<ans.back()<<endl;
}

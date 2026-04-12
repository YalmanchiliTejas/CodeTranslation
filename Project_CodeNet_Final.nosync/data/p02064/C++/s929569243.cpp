#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define PB push_back
#define P pair<int,int>



signed main(){
  int d[400][400];
  rep(i,400){
    rep(j,400){
      if(i==j) continue;
      d[i][j]=INT_MAX;
    }
  }

  int n,s,t;
  cin>>n>>s>>t;
  s--;t--;

  rep(i,n){
    if(i==s) continue;
    cout<<"? "<<s+1<<' '<<i+1<<endl;
    cout.flush();
    int c;
    cin>>c;
    d[s][i]=c;
    d[i][s]=c;
  }

  rep(i,n){
    if(i==s||i==t) continue;
    cout<<"? "<<i+1<<' '<<t+1<<endl;
    cout.flush();
    int c;
    cin>>c;
    d[t][i]=c;
    d[i][t]=c;
  }

  vector<P> v;
  rep(i,n){
    if(i==s||i==t) continue;
    if(d[s][i]+d[i][t]==d[s][t]){
      v.PB(P(d[s][i],i));
    }
  }
  sort(all(v));

  vector<int> ans;
  ans.PB(s);
  if(v.size())
    ans.PB(v[0].S);

  int j=0;
  for(int i=1;i<(int)v.size();i++){
    cout<<"? "<<v[j].S+1<<' '<<v[i].S+1<<endl;
    cout.flush();
    int c;
    cin>>c;
    //cout<<v[0].F<<' '<<' '<<c<<' '<<d[v[i].S][t]<<endl;
    if(v[j].F+c+d[v[i].S][t]==d[s][t]){
      ans.PB(v[i].S);
      j=i;
    }
  }

  ans.PB(t);

  cout<<"!";
  rep(i,ans.size()){
    cout<<" "<<ans[i]+1;
  }
  cout<<endl;

}

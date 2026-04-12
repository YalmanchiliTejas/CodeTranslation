#include <bits/stdc++.h>
using namespace std;

using Int = long long;
const char newl = '\n';

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}
template<typename T=int>
vector<T> read(size_t n){
  vector<T> ts(n);
  for(size_t i=0;i<n;i++) cin>>ts[i];
  return ts;
}

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  auto as=read(3*n);
  for(int &a:as) a--;

  int add=0;
  vector dp(n,vector(n,-n));


  vector mx(n,-n);
  int all=-n;

  using T = tuple<int, int, int>;
  vector<T> qs;
  auto preupd=[&](int x,int y,int v){
    qs.emplace_back(x,y,v);
  };
  auto upd=[&](int x,int y,int v){
    chmax(dp[x][y],v);
    chmax(dp[y][x],v);
    chmax(mx[x],v);
    chmax(mx[y],v);
    chmax(all,v);
  };
  upd(as[0],as[1],0);


  auto same=[&](int a,int b,int c){return a==b and b==c;};
  for(int i=2;i+3<=(int)as.size();i+=3){
    int x=as[i+0];
    int y=as[i+1];
    int z=as[i+2];

    if(same(x,y,z)){
      add++;
      continue;
    }

    for(int k=0;k<n;k++){
      preupd(x,k,dp[y][k]+(y==z));
      preupd(y,k,dp[z][k]+(z==x));
      preupd(z,k,dp[x][k]+(x==y));

      preupd(x,k,mx[k]);
      preupd(y,k,mx[k]);
      preupd(z,k,mx[k]);
    }

    preupd(x,y,all);
    preupd(y,z,all);
    preupd(z,x,all);

    preupd(x,y,dp[z][z]+1);
    preupd(y,z,dp[x][x]+1);
    preupd(z,x,dp[y][y]+1);

    for(auto [a,b,c]:qs) upd(a,b,c);
    qs.clear();
  }

  int ans=0;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      chmax(ans,dp[i][j]+same(i,j,as.back()));
  cout<<ans+add<<newl;
  return 0;
}

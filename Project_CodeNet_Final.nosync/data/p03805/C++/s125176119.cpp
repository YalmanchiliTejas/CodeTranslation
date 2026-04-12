#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;
typedef long long ll;
using Graph =vector<int>;
typedef pair<int,int> P;
int G[10][10];
int N,M,a,b,ans=0;
int main(){
  cin>>N>>M;
  rep(i,10){
    rep(j,10) G[i][j]=0;
  }
  rep(i,M){
    cin>>a>>b;
    a-=1;b-=1;
    G[a][b]=1;
    G[b][a]=1;
  }
  vector<int> v;
  for(int i=1;i<N;++i){
    v.push_back(i);
  }
  do {
    int s=0;
    bool f=true;
    for(auto x:v){
      if (!G[s][x]) f=false;
      s=x;
    }
    if (f) {
      ans+=1;
    }
  }while(next_permutation(v.begin(),v.end()));
  cout <<ans<<endl;
}

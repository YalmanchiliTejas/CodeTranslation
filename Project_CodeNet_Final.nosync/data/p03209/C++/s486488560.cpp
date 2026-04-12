#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

int main(){
  ll n,x;
  cin>>n>>x;
  --x;
  vector<vector<ll>> index(n+1,vector<ll>(3));
  vector<ll> p(n+1);
  index[0][0]=0;
  index[0][1]=0;
  index[0][2]=0;
  p[0]=1;
  for(int i =1; i <= n; i++){
    index[i][0]=0;
    index[i][2]=(index[i-1][2]+1)*2+3-1;
    index[i][1]=index[i][2]/2;
    p[i]=p[i-1]*2+1;
  }
  ll ans=0;
  for(int i = n; i >= 0; i--){
    if(x==index[i][1]){
      ans+=p[i]/2+1; break;
    }
    if(x==index[i][0]) break;
    if(x==index[i][2]){
      ans+=p[i]; break;
    }
    if(index[i][0]<x && x<index[i][1]){
      x--;
    }
    if(index[i][1]<x && x<index[i][2]){
      x=x-index[i][1]-1;
      ans+=p[i]/2+1;
    }
  }
  cout<<ans<<endl;
}

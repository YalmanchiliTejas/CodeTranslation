#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int N,ans=0;
map<ll,int> mp;

int main(){
  scanf("%d",&N);
  mp[0]=-1;

  ll x,y=0;
  for(int i=0;i<N;i++){
    scanf("%lld",&x);
    y+=x;
    if(mp.count(y)>0)ans=max(ans,i-mp[y]);
    if(mp.count(y)==0)mp[y]=i;
  }
  printf("%d\n",ans);
  return 0;
}
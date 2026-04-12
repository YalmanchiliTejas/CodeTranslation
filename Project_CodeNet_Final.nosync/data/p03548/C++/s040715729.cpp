#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n)for(ll i=0;i<n;i++)

const ll INF = 1001001001;

const double PI=3.141592653;

const ll sosu = 1000000007;//大きい素数

//提出のときに言語がc＋＋似合っていることを確認する

ll f(ll x){
  if(x==1) return 1;
  return 2*f(x/2)+1;
}
int main(){
  int x,y,z;
  cin>>x>>y>>z;
  x=x-z;
  int ans=0;
  ans+=x/(y+z);
  

  cout<<ans<<endl;
  return 0;
  
}


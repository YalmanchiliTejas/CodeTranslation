#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
vector<ll> vec;
int n;
bool judge(){
  bool f=true;
  for(int i=0;i<n;i++){
    if(vec[i]>=n) f=false;
  }
  return f;
}
int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    ll a;
    cin>>a;
    vec.push_back(a);
  }
  ll ans=0;
  while(!judge()){
    sort(vec.begin(),vec.end());
    ll ma=vec[n-1]-n+1;
    ll cn=ma/n+(ma%n==0?0:1);
    ans+=cn;
    for(int i=0;i<n-1;i++) vec[i]+=cn;
    vec[n-1]-=cn*n;
  }
  cout<<ans<<endl;
}
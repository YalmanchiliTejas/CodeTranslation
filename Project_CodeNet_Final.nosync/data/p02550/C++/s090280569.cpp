#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main(){
  ll n,x,m,i;
  cin >> n >> x >> m;
  map<ll,ll> mp;
  ll ans=0;
  for(i=0;i<n;i++){
    if(mp[x]==0){
      mp[x]=1;
      ans+=x;
    }
    else{
      break;
    }
    x=x*x%m;
  }
  ll y=n-i;
  ll first=x,res=0,sum=0;
  vector<ll> jo;
  jo.push_back(0);
  while(1){
    if(i==n){
      break;
    }
    sum+=x;
    jo.push_back(sum);
    i++,res++;
    x=x*x%m;
    if(first==x){
      break;
    }
  }
  if(i==n){
    cout << ans+sum << endl;
    return 0;
  }
  cout << ans+sum*(y/res)+jo[y%res] << endl;
}
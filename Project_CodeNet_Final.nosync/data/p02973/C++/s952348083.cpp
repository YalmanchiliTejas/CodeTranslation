#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n;
  cin>>n;
  vector<ll> get,solve;
  for(int i=0;i<n;i++){
    ll a;
    cin>>a;
    get.push_back(a);
  }
  for(int i=n-1;i>=0;i--){
    ll pos=upper_bound(solve.begin(),solve.end(),get[i])-solve.begin();
    if(pos>=solve.size()) solve.push_back(get[i]);
    else solve[pos]=get[i];
  }
  cout<<solve.size()<<endl;
}

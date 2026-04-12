#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
signed main(){
  ll n,cnt=0;
  cin >> n;
  ll a[n];
  map<ll,ll> mp;
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  for(int i=n-1;i>=0;i--){
    auto it = mp.upper_bound(a[i]);
    if(it==mp.end()){
      cnt++;
    }else{
      if(it->second==1) mp.erase(it);
      else it->second--;
    }
    mp[a[i]]++;
  }
  cout <<cnt << endl;
}

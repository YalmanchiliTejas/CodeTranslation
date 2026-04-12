#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
  ll n,cnt=0;
  map<ll,ll> m;
  cin >> n;
  ll a[n];
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  for(int i=n-1;i>=0;i--){
    auto it = m.upper_bound(a[i]);
    if(it==m.end()){
      cnt++;
    }else{
      if((*it).second==1) m.erase(it);
      else (*it).second--;
    }
    m[a[i]]++;
  }
  cout << cnt<<endl;
}

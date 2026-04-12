#include <iostream>
#include <vector>
#include <bitset>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
 
using namespace std;
typedef long long ll;
 
int main(){
  ll n,x,m;
  cin >> n >> x >> m;
  vector<pair<ll,ll>> v(m,make_pair(0,-1));
  ll a=x;
  ll r=0;
  int f=0;
  for(ll i=0;i<n;i++){
    if(a==0){
      break;
    }else{
      r+=a;
      if(f==0 && v[a].second==-1){
        v[a].second=i;
        v[a].first=r;
      }else if(f==0 && v[a].second!=-1){
        r+=(r-v[a].first)*((n-i)/(i-v[a].second)-1);
        i+=(i-v[a].second)*(((n-i)/(i-v[a].second))-1);
        f=1;
      }
      a=(a*a)%m;
      //cout << r << " " << a << endl;
    }
  }
  
  cout << r << endl;

  return 0;
}

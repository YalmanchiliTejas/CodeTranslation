//#include <boost/multiprecision/cpp_dec_float.hpp>
//#include <boost/multiprecision/cpp_int.hpp>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <math.h>
#include <algorithm>
#include <bitset>
using namespace std;
//namespace mp = boost::multiprecision;
//using llll = mp::cpp_int;
// 仮数部が1024ビットの浮動小数点数型(TLEしたら小さくする)
//using Real = mp::number<mp::cpp_dec_float<1024>>;
using ll = long long;
const double EPS = 1e-10;
const ll MOD = 7+(1e+9);

struct s_t{
  ll a,b;
};
bool asc(s_t left,s_t right) {
  return left.a == right.a ? left.b > right.b : left.a < right.a;
}

int main(){
  ll n;
  cin>>n;
  vector<ll>v(n,0);
  vector<s_t>v2;
  s_t zz;
  for(ll i=0;i<n;i++){
    cin>>v[i];
    zz={v[i],i};
    v2.push_back(zz);
  }
  sort(v2.begin(),v2.end(),asc);
  multiset<ll>st;
  st.insert(v2[0].b);
  for(ll i=1;i<n;i++){
    auto itr=st.lower_bound(v2[i].b);
    if(itr!=st.begin()){
      itr--;
      st.erase(itr);
    }
    st.insert(v2[i].b);
    // for(auto j=st.begin();j!=st.end();j++){
    //   cout<<*j<<" ";
    // }
    // cout<<endl;
  }
  ll ans=st.size();
  cout<<ans<<endl;
}

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
#include <iomanip>
using namespace std;
//namespace mp = boost::multiprecision;
//using llll = mp::cpp_int;
// 仮数部が1024ビットの浮動小数点数型(TLEしたら小さくする)
//using Real = mp::number<mp::cpp_dec_float<1024>>;
using ll = long long;
const double EPS = 1e-10;
const ll MOD = 9223372036854775807;

#define max 10000
ll big=1e9+7;
ll ff=0;
vector<ll> p(max,1);
vector<ll> ip(max,1);
ll pow_ans(ll x, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) {
          res *= x;
          res %= big;
        }
        x *= x;
        x %= big;
        n >>= 1;
    }
    return res;
}
void initialize(){
  for(int i=1;i<max;i++){
    p[i]=p[i-1]*i%big;
  }
  for(int i=1;i<max;i++){
    ip[i]=pow_ans(p[i],big-2);
  }
}
ll nPk(int i,int j){
  if(ff==0){
    initialize();
    ff=1;
  }
  if(i<0||j<0||i<j)return 0;
  else{
    ll tem;
    tem=p[i]*ip[i-j]%big;
    return tem;
  }
}
ll nCk(int i,int j){
  if(ff==0){
    initialize();
    ff=1;
  }
  if(i<0||j<0||i<j)return 0;
  ll tmp=nPk(i,j);
  tmp=tmp*ip[j]%big;
  return tmp;
}

int main(){
  //cout<<fixed<<setprecision(10);
  ll n,k,kk,ans=0;
  string s;
  cin>>s>>k;
  kk=k;
  n=s.size();
  ll i,j;
  for(j=0;k>0&&j<n;){
    for(i=1;i<n-j;i++){
      if(i<k)continue;
      ans+=9*nCk(i-1,k-1)*pow_ans(9,k-1);
    }
    if(!(i<k))ans+=(s[j]-'0'-1)*nCk(i-1,k-1)*pow_ans(9,k-1);
    j++;
    while(s[j]=='0'&&j<n)j++;
    k--;
  }
  ll f=0;
  for(ll q=0;q<n;q++){
    if(s[q]!='0')f++;
  }
  if(f>=kk)ans++;
  cout<<ans<<endl;
}

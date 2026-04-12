#include <iostream>
#include <sstream>
#include <stdio.h>
#include<vector>
#include<climits>
#include<algorithm>
#include<bitset>
#include<cmath>
#include<functional>
#include <numeric>
#include <map>
#define FORi(N) for(int i=0;i<N;++i)
#define FORj(N) for(int j=0;j<N;++j)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
ll gcd(ll m,ll n){
  if(n==0)return abs(m);
  return(gcd(n,m%n));
}
void putYN(bool b){
  if(b){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
}
int main(){
  ll N;
  cin>>N;
  vector<ll> H(N);
  FORi(N){
    cin>>H[i];
  }
  ll num=1;
  ll max=H[0];
  FORi(N-1){
    if(H[i+1]>=max){
      max=H[i+1];
      ++num;
    }
  }
  cout<<num<<endl;
  return 0;
}

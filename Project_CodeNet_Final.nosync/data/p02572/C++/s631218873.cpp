#include <stdlib.h>
#include <cmath>
#include <cstdio>
#include <cstdint>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;

#define MOD 1000000000+7

int main(){
  int N;
  cin >> N;
  vector<ll> A(N);
  vector<ll> sum(N);
  for(int i=0;i<N;++i){
    cin >> A.at(i);
    if(i!=0) sum.at(i)=sum.at(i-1)+A.at(i);
    else sum.at(i)=A.at(i);
    sum.at(i)%=1000000007;
  }

  ll ans=0;
  for(int i=0;i<N;++i){
    ll temp=sum.at(N-1)-sum.at(i);
    if(temp<0) temp=MOD+temp;
    ans=ans+temp*A.at(i)%1000000007;
    ans%=1000000007;
  }

  cout << ans << endl;
  
  return 0;
}

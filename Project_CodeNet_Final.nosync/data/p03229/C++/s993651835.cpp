#include <iostream>
#include <cstring>
#include <map>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <queue>
#include <list>
#include <numeric>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <math.h>
#include <stack>
#include <climits>
#include <bitset>
#include <utility>


using namespace std;
typedef long long ll;

//最小公倍数
ll gcd(ll x, ll y) {
  ll tmp = 0;
  if (x < y){
    tmp=x;
    x=y;
    y=tmp;
  }
  while (y > 0) {
    ll r = x % y;
    x = y;
    y = r;
  }
  return x;
}

//最大公倍数
ll lcm(ll x,ll y){
  return x/gcd(x,y)*y;
}

//階乗
ll kaijo(ll k){
    ll sum = 1;
    for (ll i = 1; i <= k; ++i)
    {
        sum *= i;
        sum%=1000000000+7;
    }
    return sum;
}

//for(int i = ; i < ; i++){}

ll lmax(ll s,ll t){
  if(s>t){
    return s;
  }
  else{
    return t;
  }
}

ll lmin(ll s,ll t){
  if(s<t){
    return s;
  }
  else{
    return t;
  }
}
// ここから開始

int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin>>a[i];
  }
  ll sum = 0;
  ll sum2 = 0;
  sort(a.begin(),a.end());
 
  for(int i = 0; i < n/2-1; i++){
    sum+=a[n-1-i]*2;
    sum2-=a[i]*2;
  }
  
  for(int i = 0; i < (n-1)/2; i++){
    sum-=a[i]*2;
    sum2+=a[n-1-i]*2;
  }
  
  
  if(n%2==0){
    sum-=a[n/2-1];
    sum+=a[n/2];
    sum2-=a[n/2-1];
    sum2+=a[n/2];
  }
  else{
    sum+=a[n/2];
    sum+=a[n/2+1];
    sum2-=a[n/2];
    sum2-=a[n/2-1];
  }
  
  cout<<lmax(sum,sum2)<<endl;
  
  return 0;
}

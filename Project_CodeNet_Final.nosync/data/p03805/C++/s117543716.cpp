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
int n,m;
int g[10][10];

int main(){
  cin>>n>>m;
  for(int i = 0; i < m; i++){
    int a,b;
    cin>>a>>b;
    a--; b--;
    g[a][b] = g[b][a] = 1;
  }
  vector<int> array(n-1);
  for(int i = 1; i < n; i++){
    array[i-1] = i;
  }
  int c=0;
  do{
    int now = 0;
    for(int i = 0; i < array.size(); i++){
      if(g[now][array[i]] == 0) break;
      now = array[i];
      if(i == array.size()-1) c++;
    }
  }while(next_permutation(array.begin(), array.end()));
  cout<<c<<endl;
  return 0;
}

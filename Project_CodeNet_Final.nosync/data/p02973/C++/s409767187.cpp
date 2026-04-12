//#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<numeric>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<list>
using namespace std;

typedef long long ll;

#define INF 1000000000000000

int main(){
  ll n;
  cin >> n;
  ll a[n];
  for(int i=0;i<n;i++) cin >> a[i];
  ll d[n+1];
  d[0] = -INF;
  for(int i=1;i<n+1;i++){
    a[i-1] *= -1; 
    d[i] = INF;
  }
  for(int i=0;i<n;i++){
    auto itr = upper_bound(d,d+n+1,a[i]);
    ll index = itr - d;
    d[index] = a[i];
  }
  for(int i=n;i>=1;i--){
    if(d[i]!=INF){
      cout << i << endl;
      break;
    }
  }

  return 0;
}

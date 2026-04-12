//A.cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){return b!=0?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
const ll mod=1e9+7;


int main(){
  int n;
  cin >> n;
  int h[n];
  rep(i,n) cin >> h[i];
  int tall = h[0];
  int cnt = 1;
  for(int i = 1; i < n; i++){
    if(h[i] >= tall){
      cnt++;
      tall = h[i];
    }
  }
  printf("%d\n", cnt);
  return 0;
}

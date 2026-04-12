#include <bits/stdc++.h>
 
using namespace std;
 
#define x first
typedef pair<int,int> pii;

typedef long long ll;
const int mod = 1000000007;
const int oo = 1e9;
const int base = 27;
const int N = 1001;
const int M = 5001;

int n;
ll a[N];

bool check(ll md){
  for(ll nw = max(0ll,md-n*n);nw <= md ; nw++){
    ll g =0;
    for (int i = 0; i < n; ++i){
      ll rem = max(0ll,nw+a[i]-(n-1));
      ll nd = (rem/(n+1))+(rem%(n+1)!=0);
      g += nd;
    }
    if(g <= nw)return true;
  }
  return false;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i)scanf("%lld",a+i);
  ll lo = 0 , hi = 1e18,best =-1;
  while(lo <= hi){
    ll md = (lo + hi)/2;
    if(check(md)){
      best = md;
      hi = md-1;
    }else{
      lo = md+1;
    }
  }
  cout <<  best << endl;
  return 0;
}
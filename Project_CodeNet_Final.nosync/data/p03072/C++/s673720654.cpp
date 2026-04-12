#include<vector>
#include<iostream>
#include<algorithm>
#include<functional>
#include<string>
#include<limits.h>
#include<cmath>
#include<queue>
#include<map>
#define rep(i,n) for (int i=0; i<n; i++)
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b){
  ll r;
  while ((r=a%b)){a=b;b=r;}
  return b;
}

int main(){

  int n; cin >> n;
  vector<int> h(n); rep(i,n){cin >> h[i];}
  int ans=1;

  for (int i=1; i<n; i++){
    int can=1;
    for (int j=0; j<i; j++){
      if (h[j]>h[i]){can=0;break;}
    }
    if (can==1){ans++;}
  }

  cout << ans;
  

  return 0;
}

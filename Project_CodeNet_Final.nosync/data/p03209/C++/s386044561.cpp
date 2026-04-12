#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long n,x,ans=0;
  cin >> n >> x;
  vector<long> layer(51),patty(51);
  layer[0]=1,patty[0]=1;
  for(long i=1;i<=50;i++) layer[i]=layer[i-1]*2+3,patty[i]=patty[i-1]*2+1;
  while(n>0) {
    if(x==1) break;
    if(x==layer[n]) {
      ans+=patty[n];
      break;
    }
    if(x==layer[n]/2+1) {
      ans+=patty[n-1]+1;
      break;
    }
    if(x<layer[n]/2+1) {
      n--,x--;
    } else {
      x-=layer[n-1]+2,ans+=patty[n-1]+1,n--;
    }
  }
  if(n==0) ans++;
  cout << ans << endl;
}
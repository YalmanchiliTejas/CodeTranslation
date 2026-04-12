#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
typedef long long int ll;
using namespace std;
ll z[51],p[51];
ll solve(ll n,ll x);
int main() {
  ll n,x;
  cin>>n>>x;
  p[0]=1;
  z[0]=1;
  for(int i=1;i<51;i++){
    p[i]=p[i-1]*2+1;
    z[i]=z[i-1]*2+3;
  }
  
  cout<<solve(n,x)<<endl;
}
ll solve(ll n,ll x){
  if(n==0){
    if(x==0)return 0;
    if(x==1)return 1;
  }
  if(x==1)return 0;
  if(x>1&&x<=z[n-1]+1)return solve(n-1,x-1);
  if(x==z[n-1]+2)return p[n-1]+1;
  if(x>z[n-1]+2&&x<=z[n-1]*2+2)return p[n-1]+solve(n-1,x-2-z[n-1])+1;
  if(x==z[n-1]*2+3)return p[n];
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int nmax=55;
ll sum[nmax],p[nmax];
ll f(ll n,ll x){
  if(x==0||x==1){
    if(n==0&&x==1){
      return 1;
    }
    else{
      return 0;
    }
  }
  else if(x<=1+sum[n-1]){
    return f(n-1,x-1);
  }
  else if(x==2+sum[n-1]){
    return p[n-1]+1;
  }
  else if(x<=2+2*sum[n-1]){
    return p[n-1]+1+f(n-1,x-2-sum[n-1]);
  }
  else{
    return p[n];
  }
}
int main(){
  ll n,x;
  cin >> n >> x;
  p[0]=1;
  sum[0]=1;
  for(int i=1;i<=n;i++){
    sum[i]=3+sum[i-1]*2;
    p[i]=1+p[i-1]*2;
  }
  cout << f(n,x) << endl;
}
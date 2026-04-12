#include <iostream>
using namespace std;

typedef long long ll;

ll solve(int n,ll m){
  ll a[51],b[51];
  a[0]=1,b[0]=1;
  for(int i=0;i<50;i++){
    a[i+1]=2*a[i]+3;
    b[i+1]=2*b[i]+1;
  }
  if(n==0&&m==1){
    return 1;
  }
  else if(m==1){
    return 0;
  }
  else if(2<=m&&m<=1+a[n-1]){
    return solve(n-1,m-1);
  }
  else if(m==2+a[n-1]){
    return solve(n-1,a[n-1])+1;
  }
  else if(m>2+a[n-1]&&m!=a[n]){
    return solve(n-1,m-2-a[n-1])+b[n-1]+1;
  }
  else{
    return b[n];
  }
}

int main(){
  int n;
  ll x;
  cin >> n >> x;
  cout << solve(n,x) << endl;
}
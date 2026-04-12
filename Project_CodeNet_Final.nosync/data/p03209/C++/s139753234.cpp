#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int MAXN=51;
int n; ll k;
ll p[MAXN],sum[MAXN];

ll calc(int n,ll k){
  if(n==0){
    if(k<=0) return 0;
    else return 1;
  }else if(k<=sum[n-1]+1){
    return calc(n-1,k-1);
  }else{
    return p[n-1]+1+calc(n-1,k-sum[n-1]-2);
  }
}

int main(){
  cin>>n>>k;
  sum[0]=1;
  p[0]=1;
  for(ll i=1;i<=n;i++){
    sum[i]=2*sum[i-1]+3;
    p[i]=p[i-1]*2+1;
  }
  cout<<calc(n,k)<<endl;
}
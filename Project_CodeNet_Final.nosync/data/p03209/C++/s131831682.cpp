#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;

const ll MOD=1000000007;

ll gcd1(ll a,ll b){
  if(a==0 && b==0)return 0;
  ll n;
  while(a%b!=0){
    n=a%b;
    a=b;
    b=n;
  }
  return b;
}

ll solveLinear1(ll n,ll m,ll c){
  if(n==0 && m==0)return 0;
  ll a[100],b[100];
  a[0]=n;b[0]=m;
  int i=1;
  while(b[i-1]!=0){
    a[i]=b[i-1];
    b[i]=a[i-1]%b[i-1];
    i++;
  }
  n=i;
  if(c%a[n-1]!=0){
    return 0;
  }
  ll x=c/a[n-1],y=0;
  for(i=1;i<n;i++){
    ll cnt=x;
    x=y;
    y=cnt-(a[n-i-1]/b[n-i-1])*y;
  }
  return x;
}

ll modRev(ll a,ll p){
  ll n=solveLinear1(a,p,1);
  n=n%p;
  if(n<0)return n+p;
  return n;
}

ll L[51];
ll a[51];

ll patty(ll x,int n){
  if(x<=0)return 0;
  if(n==0)return 1;
  if(x>=L[n])return a[n];
  ll cnt=patty(x-1,n-1)+patty(x-2-L[n-1],n-1);
  if(x>L[n-1]+1)cnt++;
  return cnt;
}

int main(){
  int i,j,k,cnt=0;
  int n;ll x;
  cin>>n>>x;
  L[0]=1;
  a[0]=1;
  for(i=1;i<=50;i++){
    L[i]=2*L[i-1]+3;
    a[i]=2*a[i-1]+1;
  }
  cout<<patty(x,n)<<endl;
}

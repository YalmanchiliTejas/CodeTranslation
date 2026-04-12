#include<iostream>
using namespace std;
typedef long long int ll;

ll p2[100]={};

ll pow2(ll a){
  if(a<2) return a+1;
  else if(p2[a]!=0) return p2[a];
  else{
    p2[a]=pow2(a/2)*pow2(a/2)*pow2(a-2*(a/2));
    return p2[a];
  }
}

ll mac(ll n,ll x){
  if(x==0) return 0;
  else if(n==0) return 1;
  else if(x<=pow2(n+1)-2) return mac(n-1,x-1);
  else if(x==pow2(n+2)-3) return pow2(n+1)-1;
  else return pow2(n)+mac(n-1,x-pow2(n+1)+1);
}

int main(){
  ll n,x,ans=0;
  cin>>n>>x;
  cout<<mac(n,x);
}
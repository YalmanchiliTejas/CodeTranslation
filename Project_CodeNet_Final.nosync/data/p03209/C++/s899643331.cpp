#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

long long int a[51],b[51];

ll burger(ll c,ll d){
  if(c==0) return 1;
  else if(d==1) return 0;
  else if(d>1 && d<=(1+a[c-1])) return burger(c-1,d-1);
  else if(d==(2+a[c-1])) return b[c-1]+1;
  else if(d>(2+a[c-1]) && d<=(2+2*a[c-1])) return b[c-1]+1+burger(c-1,d-2-a[c-1]);
  else if(d==(3+2*a[c-1])) return 2*b[c-1]+1;
}
int main(){
  a[1]=5;b[1]=3;
  a[0]=1;b[0]=1;
  for(int i=2;i<51;i++){
    a[i]=a[i-1]*2+3;
    b[i]=b[i-1]*2+1;
  }
  ll n,x;
  cin>>n>>x;
  ll ans=burger(n,x);
  cout<<ans<<endl;
  return 0;
}

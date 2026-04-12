#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  ll n,x,m;
  cin>>n>>x>>m;
  
  int a=-1,b=n;
  vector<int> A(m+1),B(m+3);
  ll t=x;
  A[1]=t;
  B[t]=1;
  for(int i=2;i<=n;i++){
    t=t*t%m;
    if(B[t]==0){
      A[i]=t;
      B[t]=i;
    }
    else{
      a=B[t];
      b=i-1;
      break;
    }
  }
  
  ll c=b-a+1;
  ll d=(n-a+1)/c-1;
  ll sum=0;
  for(int i=1;i<=b;i++) sum+=A[i];
  if(a!=-1) for(int i=a;i<=b;i++) sum+=d*A[i];
  ll e=n-b-((n-a+1)/c-1)*c;
  if(a!=-1) for(int i=0;i<e;i++) sum+=A[a+i];
  
  cout<<sum<<endl;
  
  return 0; 
}
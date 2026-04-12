#include<iostream>
using namespace std;
#define ll long long

int N;
ll X;
ll a[50],p[50];

ll fact(int n,ll x){
  if(n==0) return 1;
  if(x==1) return 0;
  if(x<=1+a[n-1]) return fact(n-1,x-1);
  if(x==2+a[n-1]) return p[n-1]+1;
  if(x<=2*a[n-1]+2) return p[n-1]+1+fact(n-1,x-a[n-1]-2);
  if(x==2*a[n-1]+3) return p[n-1]*2+1;
}
int main(){
  cin>>N>>X;
  a[0]=p[0]=1;
  for(int i=1;i<N;i++){
    a[i]=2*a[i-1]+3;
    p[i]=2*p[i-1]+1;
  }
  cout<<fact(N,X)<<endl;
  return 0;
}
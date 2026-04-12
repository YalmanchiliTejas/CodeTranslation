#include <iostream>
using namespace std;
long long a[52],p[52];

long long f(int n,long long x){
  if(n==0)return p[0];
  if(x==1)return 0;
  if(x<1+a[n-1])return f(n-1,x-1);
  if(x==1+a[n-1])return p[n-1];
  if(x==1+a[n-1]+1)return p[n-1]+1;
  if(x<1+a[n-1]+1+a[n-1])return p[n-1]+1+f(n-1,x-2-a[n-1]);
  if(x>=1+a[n-1]+1+a[n-1])return 2*p[n-1]+1;
}
int main(){
  int n,i,j;
  long long x;
  cin >> n >> x;
  a[0]=p[0]=1;
  for(i=1;i<=n;i++){
    a[i]=3+2*a[i-1];
    p[i]=1+2*p[i-1];
  }
  cout << f(n,x) << endl;
  return 0;
}

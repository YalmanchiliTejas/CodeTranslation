#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int N=200010;

int n,a[N],b[N*3],l,r;

#define rea(x) scanf("%d",&x)

int main(){
  rea(n); l=n+1; r=n+2;
  for(int i=1;i<=n;i++) rea(a[i]);
  for(int i=1;i<=n;i++){
    if(i&1) b[r++]=a[i];
    else b[l--]=a[i];
  }
  if(~n&1) for(int i=l+1;i<r;i++) printf("%d ",b[i]);
  else for(int i=r-1;i>l;i--) printf("%d ",b[i]);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  long long a[n],b[n],c[n];
  for(int i=0;i<n;i++){
    long long k;
    cin>>k;
    a[i]=k;
  }
  b[0]=0;
  b[1]=max(a[0],a[1]);
  c[0]=a[0];
  c[1]=b[1];
  b[2]=max(b[1],a[2]);
  c[2]=a[0]+a[2];
  for(int i=3;i<n;i++){
    if(i%2==1){
      b[i]=max(a[i]+b[i-2],a[i-1]+c[i-3]);
      c[i]=b[i];
    }
    else {
      b[i]=max(max(c[i-2],a[i-1]+b[i-3]),a[i]+b[i-2]);
      c[i]=c[i-2]+a[i];
    }
  }
  cout<<b[n-1]<<endl;
}

#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int a[200005];
int b[200005];

int main(){
  int n;
  cin>>n;
  rep(i,n)cin>>a[i];
  int j=0;
  for(int i=n-1;i>=0;i-=2)
    b[j++]=a[i];
  for(int i=n&1;i<n;i+=2)
    b[j++]=a[i];
  rep(i,n){
    cout<<b[i];
    if(i!=n-1)cout<<" ";
    else cout<<"\n";
  }
  return 0;
}

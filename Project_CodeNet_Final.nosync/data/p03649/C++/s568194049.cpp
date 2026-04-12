#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll n,c=0,d=0;
  cin>>n;
  ll a[n],b[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
    b[i]=a[i]/n;
    d+=a[i]/n;
    a[i]%=n;
  }
  c+=d;
  while(d!=0){
    for(int i=0;i<n;i++){
      a[i]+=d-b[i];
    }
    d=0;
    for(int i=0;i<n;i++){
      b[i]=a[i]/n;
      d+=a[i]/n;
      a[i]%=n;
    }
    c+=d;
  }
  cout<<c;
}
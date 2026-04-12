#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int n; cin>>n;
  vector<ll> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  sort(a.begin(),a.end());
  
  ll sum=0;
  int m=(n+1)/2;
  if(n%2==0){
    for(int i=0;i<m-1;i++){
      sum-=2*a[i];
    }sum-=a[m-1];
    for(int i=m+1;i<n;i++){
      sum+=2*a[i];
    }
    sum+=a[m];
    cout<<sum<<endl;
    return 0;
  }ll ma;
  for(int i=m;i<n;i++)sum+=2*a[i];
  sum-=a[m-1]+a[m-2];
  for(int i=0;i<m-2;i++)sum-=2*a[i];
  ma=sum;sum=0;
  sum+=a[m-1]+a[m];
  for(int i=m+1;i<n;i++)sum+=2*a[i];
  for(int i=0;i<m-1;i++)sum-=2*a[i];
  cout<<max(ma,sum)<<endl;
}
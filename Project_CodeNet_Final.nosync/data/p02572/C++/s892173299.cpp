#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  long n;cin>>n;
  long long a[n];
  for(long i=0;i<n;i++){
  	cin>>a[i];
  }
  long long x=0;
  long long m=1000000007;
  long long ssum[n];
  ssum[n-1]=a[n-1];
  for(int i=n-2;i>=0;i--){
  	ssum[i]=(a[i]+ssum[i+1])%m;
  }
  // for(int i=0;i<n;i++)cout<<ssum[i]<<" ";
  // cout<<endl;
  for(int i=0;i<n-1;i++){
  	x=(x+(a[i]*ssum[i+1])%m)%m;
  }
  cout<<x<<"\n";
 return 0; 
}
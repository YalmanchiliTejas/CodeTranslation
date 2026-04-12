#include<bits/stdc++.h>
using namespace std;

int main(){
 long long int m = 1000000007;
 int n;
  cin>>n;
  vector<long long int>v(n),pre(n);
  for(int i=0;i<n;i++)
  {
    cin>>v[i];
  }
  pre[n-1]=v[n-1];
  for(int i=n-2;i>=0;i--)
  {
    pre[i]=(v[i]%m+pre[i+1]%m)%m;
  }
  
 long long int ans=0;
  
  for(int i=0;i<n-1;i++)
  {
    ans = (ans%m + (v[i]%m * pre[i+1]%m)%m)%m;
    if(ans<0)
      ans = (ans%m+m)%m;
     //cout<<ans<<endl;
  }
  cout<<ans%m<<endl;
}

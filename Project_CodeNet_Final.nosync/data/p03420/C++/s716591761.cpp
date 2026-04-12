#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,k;
  cin>>n>>k;
  long long ans=0;
  for(int i=1;i<=n;i++)
  {
    if(i<=k)continue;
    ans+=(long long)(i-k)*(n/i)+max(((n%i)-k+1-(k==0)),0);
    //cout<<i<<" "<<count<<endl;
    
  }
  cout<<ans<<endl;

  return 0;
}
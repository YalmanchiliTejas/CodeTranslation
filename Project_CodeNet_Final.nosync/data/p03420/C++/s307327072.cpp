#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,k,d,r,ans;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>n>>k;
  if(k==0)
  {
    cout<<n*n<<endl;
    return 0;
  }
  for(long i=k+1;i<=n;i++)
  {
    d=n/i;
    r=n%i;
    ans+=((i-k)*d);
    if(r<k)continue;
    ans+=r-k+1;
  }
  cout<<ans<<endl;
  return 0;
}

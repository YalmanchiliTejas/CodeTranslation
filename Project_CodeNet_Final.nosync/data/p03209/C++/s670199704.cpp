#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  long long x;
  cin>>n>>x;
  vector<long long>lyr(n+1);
  vector<long long>p(n+1);
  p[0]=1;
  lyr[0]=1;
  for(int i=1;i<=n;i++)
  {
    p[i]=(2*p[i-1])+1;
    lyr[i]=(2*lyr[i-1])+3;
  }
  long long ans=0;
  long long l=1;
  long long r=lyr[n];
  long long mid=(l+r)/2;
  int level=n;
  while(l<r)
  {
    --level;
    if(x==mid)
    {
      ans+=p[level]+1;
      break;
    }
    else if(x==l)break;
    
    else if(x==r)
    {
      ans+=p[level+1];
      break;
    }
    
    else if(x>mid)
    {
      l=mid+1;
      r--;
      ans+=p[level]+1;
    }
    else if(x<mid)
    {
      r=mid-1;
      l++;
    }
    mid=(l+r)/2;
  }
  if(l==r)ans++;
  cout<<ans<<endl;
  return 0;
}
      
      
      
      
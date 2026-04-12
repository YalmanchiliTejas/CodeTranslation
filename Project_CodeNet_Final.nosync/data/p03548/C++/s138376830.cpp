#include<bits/stdc++.h>
using namespace std;

int main()
{
  int x,y,z,ans;
  cin>>x>>y>>z;
  for(int i=int(ceil(x/y));i>=1;i--)
  {
    if(i*y+(i+1)*z<=x)
       {
         ans = i;
         break;
       }
  }
  cout<<ans<<"\n";
  return 0;
}

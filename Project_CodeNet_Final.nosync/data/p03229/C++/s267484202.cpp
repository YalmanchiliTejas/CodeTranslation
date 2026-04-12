#include<bits/stdc++.h>
const int maxs=1e9+1;
int a[100002];
using namespace std;
int main()
{
int n,i,j,k;
    cin>>n;
    int maxs=0;
  for(i=0;i<n;i++)
  {
      cin>>a[i];
  }
  sort(a,a+n);
  int be=1,ed=n-1,s=0,t=0;
   long long sum=0;
    while(be<=ed)
    {
        int t1=abs(a[be]-a[t]),t2=abs(a[be]-a[s]),t3=abs(a[ed]-a[s]),t4=abs(a[ed]-a[t]);
      if(t1>=t2&&t1>=t3&&t1>=t4)
      {
          sum+=t1;
          t=be;be++;
      }
      else if(t2>=t3&&t2>=t1&&t2>=t4)
      {
          sum+=t2;
          s=be;be++;
      }
      else if(t3>=t1&&t3>=t2&&t3>=t4)
      {
          sum+=t3;
          s=ed;ed--;
      }
      else if(t4>=t3&&t4>=t1&&t4>=t2)
      {
          sum+=t4;
          t=ed;ed--;
      }
    }
    cout<<sum<<endl;
return 0;
}

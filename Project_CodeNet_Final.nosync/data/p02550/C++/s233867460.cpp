#include<iostream>
#include<algorithm>
using namespace std;
int main (void)
{ 
  long long int n,x,m,ans=0;;
  int i,j,k,d[1000000],dis,l1,l2;
  bool c[1000000];
  
  for(i=0;i<1000000;i++){c[i]=0;d[i]=0;}
  cin>>n>>x>>m;
  c[x]=1;
  d[1]=x;
  if(n<10000000)
  {
    for(i=0;i<n;i++)
    {
     ans+=x;
     x=(x*x)%m;
    }
    cout<<ans<<endl;
    return 0;
  }
  
  
  for(i=0;i<n;i++)
  {
    x=x*x;
    x=x%m;
    if(c[x]==0){c[x]=1;d[i+2]=x;}
    else
    {
      for(j=1;j<n;j++)
      {
        if(d[j]==x)
        {
          dis=i+2-j;
          l2=i+2;
          l1=j;
          break;
        }
      }
      break;
    }
  }
  long long int loop=(n-l1+1)/dis,nokori=(n-l1+1)%dis;
   for(i=l1;i<l2;i++){ans+=d[i];}
   ans*=loop;
  
   for(i=1;i<l1;i++){ans+=d[i];}
  
   for(i=0;i<nokori;i++)
   {
     ans+=d[i+l1];
   }
  
  cout<<ans<<endl;

  
  return 0;
}
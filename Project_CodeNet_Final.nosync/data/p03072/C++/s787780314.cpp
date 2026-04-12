#include<iostream>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int h[n+1];
  for(int i=1;i<=n;i++)
  {
    cin>>h[i];
  }
  int k=0;
  for(int i=2;i<=n;i++)
  {
    int c=0;
    for(int j=1;j<i;j++)
    {
       if(h[j]>h[i])
       {
         c++;
       }
    }
    if(c==0)
      k++;
  }
  cout<<k+1;
  return 0;
}
      
         
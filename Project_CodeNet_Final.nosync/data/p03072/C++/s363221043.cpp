#include<iostream>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int a[n+1];
  int maxv=0;
  int s=0;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];
    if(a[i]>=maxv)
    {
      maxv=a[i];
      s++;
    }
      
  }
  cout<<s;
}
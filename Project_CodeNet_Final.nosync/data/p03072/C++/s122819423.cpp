#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,i;
  cin>>n;
  int a[n],max=0,c=0;
  for(i=0;i<n;i++)
  {
    cin>>a[i];
    if(a[i]>max) max=a[i];
    if(a[i]==max) c++;
  }
  cout<<c;
  return 0;
}
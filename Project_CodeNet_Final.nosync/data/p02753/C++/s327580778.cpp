#include<bits/stdc++.h>
using namespace std;
int main()
{
  string a;
  cin>>a;
  int i,j,k=0;
  for(i=0;i<a.length();i++)
  {
    for(j=i;j<a.length();j++)
    {
      if(a[i]!=a[j])
      {
        k=1;
      }
    }
  }
  if(k)
    cout<<"Yes";
  else
    cout<<"No";
}
  

#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t,n,i,j=0,c=0;
  cin>>t;
  for(i=0;i<t;i++)
  {
     cin>>n;
     if(n>=c)
     {
         c=n;
         j++;
     }
  }
 cout<<j<<"\n";


return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,i,j,a,b,c,k,x,y;
int main()
{
  cin>>a>>b>>c>>x>>y;
  k=a*x+b*y;
  k=min(k,2*c*max(x,y));
  if(x>y)k=min(k,2*c*y+a*(x-y));
  else k=min(k,2*c*x+b*(y-x));
  cout<<k;
}
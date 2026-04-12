#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
ll a,b,c,d,e,i,j,k,x,y,l=0,lt=0;
cin>>a>>b>>c>>x>>y;
if(c*2<a+b)
{
k=min(x,y);
  l=l+(k)*2*c;
l=l+(a*(x-k))+(b*(y-k));
lt=max(x,y)*2*c;
cout<<min(l,lt)<<endl;
}
else
{
l=a*x+b*y;
cout<<l<<endl;
}


}
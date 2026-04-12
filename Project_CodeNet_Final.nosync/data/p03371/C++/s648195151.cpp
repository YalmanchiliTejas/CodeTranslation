#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a,b,c,x,y;cin>>a>>b>>c>>x>>y;
  int n=a+b>c*2?min(x,y):0;
  cout<<c*2*n+min(a,c*2)*(x-n)+min(b,c*2)*(y-n)<<endl;
}
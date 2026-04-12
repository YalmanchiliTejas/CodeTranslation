#include<bits/stdc++.h>

using namespace std;
int main(){
int a,b,c,x,y;
cin>>a>>b>>c>>x>>y;
int pa,pb,pt,p,pab,pall;
pa=x*a;
pb=y*b;
pt=pa+pb;
if(x>y)
{
    pab=y*c*2;
    pa=(x-y)*a;
    p=pa+pab;
    pall=2*x*c;
}
else
    {
    pab=x*c*2;
    pb=(y-x)*b;
    p=pab+pb;
    pall=2*y*c;
}
if(p>pt && pall>pt)
  cout<<pt<<endl;
else if(p<pt && p<pall)
cout<<p<<endl;
else
cout<<pall<<endl;

return 0;
}

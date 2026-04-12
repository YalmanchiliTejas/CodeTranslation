#include <iostream>
#include <algorithm>
int main(){int a,b,c,x,y,r;std::cin>>a>>b>>c>>x>>y;r=std::min(a*x+b*y,std::max(x,y)*c*2);r=std::min(r, (x<y?x*c*2+(y-x)*b:y*c*2+(x-y)*a));std::cout<<r<<"\n";}